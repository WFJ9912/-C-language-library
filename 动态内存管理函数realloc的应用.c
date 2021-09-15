#define _CRT_SECURE_NO_WARNINGS 1              
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //调整动态开辟的内存空间
    /*
    void *realloc (void*ptr, size_t size);
    1.ptr是要调整的内存地址
    2.size调整之后新大小
    3.返回值为调整之后的内存起始位置
    4.这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到的空间
    5.realloc在调整内存空间的是存在两种情况：情况1：原有空间之后有足够大的空间..情况2：原有空间之后没有足够大的空间
    6.  情况1:当是情况1的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化。
        情况2:当是情况2的时候，原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小的连续空间来使用。这样函数返回的是一个新的内存地址。由于上述的两种情况，realloc函数的使用就要注意一些。
    举个例子：
    */
    int* p = (int*)malloc(5 * sizeof(int));
    if (p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            *(p + i) = i;
        }
    }
    //就是在使用malloc开辟的20个空间
    //假设这里，20个字节不能满足我们使用了
    //希望我们能够有40个字节的空间
    //这里我们可以使用realloc来调整动态
    int* ptr = realloc(p, 40);
    if (ptr == NULL)
    {
        printf("%s", strerror(errno));
    }
    else
    {
        p = ptr;
    }
    int i = 0;
    for (i = 5; i < 10; i++)
    {
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d", *(p + i));
    }
    printf("\n");
    free(p);
    p = NULL;
    return 0;
}

/*----------------------------------------------------------------
常见的动态内存错误
1.对NULL指针的解引用操作
2.对动态开辟空间的越界访问
3.对非动态开辟内存使用free释放
4.使用free释放一块动态开辟内存的一部分
5.对同一块动态内存多次释放
6.动态开辟内存忘记释放（内存泄漏）
    忘记释放不再使用的动态开辟的空间会造成内存泄漏。切记：。
*/

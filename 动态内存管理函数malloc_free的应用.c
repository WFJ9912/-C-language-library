#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
动态内存函数之-malloc
void *malloc( size_t size );
这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针
若开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查
如果参数size为0，malloc的行为标准是未定义的，取决于编译器。

动态内存函数之-free
void free( void *memblock );
这个函数是专门用来做动态内存的释放和回收的
如果参数memblock所指向的空间不是动态开辟的，那free函数的行为是未定义的。
如果参数memblock是NULL指针，则函数什么事都不做

*/
int main()
{
    //向内存申请10个整型空间
    int *p = (int*)malloc(10*sizeof(int));
    if(p == NULL)
    {
        //打印错误原因的一个方式
        printf("%s\n",strerror(errno));
    }
    else
    {
        //正常使用空间
        int i = 0;
        for(i = 0; i < 10; i++)
        {
            *(p + i) = i;
        }
        for(i = 0; i < 10; i++)
        {
            printf("%d\t",*(p+i));//0 1 2 3 4 5 6 7 8 9 
        }
        //当动态申请的空间不再使用的时候
        //就应该还给操作系统
        free(p);
        p = NULL;
    }
    return 0 ;
}
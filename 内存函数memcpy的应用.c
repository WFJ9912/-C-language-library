#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

struct S
{
    char name[20];
    int age;
};
void *my_memcpy(void *dest, const void *src, size_t num)
{
    void *ret = dest;
    assert(dest != NULL);
    assert(src != NULL);
    while (num--)
    {
        *(char *)dest = *(char *)src;
        ++(char *)dest;
        ++(char *)src;
    }
    return ret;
}
void test1()
{
    /*
    void * memcpy ( void * destination, const void * source, size_tnum );
    1.函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
    2.这个函数在遇到'\0'的时候并不会停下来。
    3.如果source和destination有任何的重叠，复制的结果都是未定义的。
    */
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    struct S arr3[] = { {"张三",20} ,{"李四",30} };
    struct S arr4[3] = {0};
    memcpy(arr2, arr1, sizeof(arr1));
    int j = 0;
    for(j=0;j<5;j++)
    {
        printf("%d ", arr2[j]);
    }
    printf("\n");

    //模拟实现
    my_memcpy(arr4, arr3, sizeof(arr3));
    int i = 0;
    for (i = 0; i < 2; i++)
    {
        printf("%s %d  ", arr4[i].name, arr4[i].age);
    }
}
int main()
{
    test1(); //memcpy函数的应用-my_memcpy模拟实现
    return 0;
}
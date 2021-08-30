#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

void *my_memmove(void *dest, const void *src, size_t count)
{
    assert(dest != NULL);
    assert(src != NULL);
    void *ret = dest;
    if (dest < src)
    {
        while (count--)
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        while (count--)
        {
            *((char *)dest + count) = *((char *)src + count);
        }
    }
    return ret;
}
void test1()
{
    /*
    void * memmove ( void * dst, const void * src, size_t count)
    C语言规定： memcpy - 只要处理不重叠的内存拷贝就可以
                memmove - 处理重叠内存的拷贝
    */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    memmove(arr + 2, arr, 20);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]); //1 2 1 2 3 4 5 8 9 10
    }
    printf("\n");

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int j = 0;
    my_memmove(arr2 + 2, arr2, 20);
    for (j = 0; j < 10; j++)
    {
        printf("%d ", arr[j]); //1 2 1 2 3 4 5 8 9 10
    }
}
int main()
{
    test1(); //memmove的应用
    return 0;
}
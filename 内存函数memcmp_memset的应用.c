#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

void test2()
{
    char arr[10] = "";
    memset(arr, '#', 10);
    int i = 0;
    for(i=0; i<10; i++)
    {
        printf("%c", arr[i]);//##########
    }
}
void test1()
{
    /*
    int memcmp ( const void *ptr1, const void *ptr2, size_t num );
    1.比较从ptr1和ptr2指针开始的num个字节
    2.返回值如下：<0   0   >0
    */
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 5, 4, 3};
    int ret = memcmp(arr1, arr2, 9);
    printf("%d\n", ret);//-1 返回一个小于0的数
    int ret2 = memcmp(arr1, arr2, 8);
    printf("%d\n", ret2);//0 相等，返回0
}
int main()
{
    test1(); //memcmp的应用--注意比较的是字节
    test2();//memset的应用--注意比较的是字节-内存设置
    return 0;
}
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
    1.�Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�
    2.����ֵ���£�<0   0   >0
    */
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 5, 4, 3};
    int ret = memcmp(arr1, arr2, 9);
    printf("%d\n", ret);//-1 ����һ��С��0����
    int ret2 = memcmp(arr1, arr2, 8);
    printf("%d\n", ret2);//0 ��ȣ�����0
}
int main()
{
    test1(); //memcmp��Ӧ��--ע��Ƚϵ����ֽ�
    test2();//memset��Ӧ��--ע��Ƚϵ����ֽ�-�ڴ�����
    return 0;
}
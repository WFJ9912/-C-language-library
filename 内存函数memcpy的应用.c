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
    1.����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
    2.�������������'\0'��ʱ�򲢲���ͣ������
    3.���source��destination���κε��ص������ƵĽ������δ����ġ�
    */
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    struct S arr3[] = { {"����",20} ,{"����",30} };
    struct S arr4[3] = {0};
    memcpy(arr2, arr1, sizeof(arr1));
    int j = 0;
    for(j=0;j<5;j++)
    {
        printf("%d ", arr2[j]);
    }
    printf("\n");

    //ģ��ʵ��
    my_memcpy(arr4, arr3, sizeof(arr3));
    int i = 0;
    for (i = 0; i < 2; i++)
    {
        printf("%s %d  ", arr4[i].name, arr4[i].age);
    }
}
int main()
{
    test1(); //memcpy������Ӧ��-my_memcpyģ��ʵ��
    return 0;
}
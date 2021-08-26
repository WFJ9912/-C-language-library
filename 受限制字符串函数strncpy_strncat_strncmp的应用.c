#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>

void test3()
{
    /*
    int strncmp (const char* str1,const char* str2,size_tnum);
    �Ƚϵ���������ַ���һ������һ���ַ�����������num���ַ�ȫ���Ƚ��ꡣ
    */
    const char *p1 = "abcdef";
    const char *p2 = "abcqwer";
    int ret = strncmp(p1, p2, 4);
    printf("%d\n", ret); //-1
    int ret1 = strncmp(p1, p2, 3);
    printf("%d\n", ret1); //0
}
void test2()
{
    /*
    char* strncat (char* destination,const char* source,size_tnum);
    1.Appends the ?rst num characters of source to destination, plus a terminating null-character.
    2.If the length of the C string in source is less than num, only the content up to the terminating null-character is copied.
    */
    char arr1[30] = "hello";
    char arr2[] = "world";
    strncat(arr1, arr2, 3);
    printf("%s\n", arr1); //hellowor00000...
}
void test1()
{
    /* 
    char* strncpy (char* destination,const char* source,size_tnum);
    1.Copies the ?rst num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.
    2.����num���ַ���Դ�ַ�����Ŀ��ռ䡣
    3.���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��0��ֱ��num����
    */
    char arr1[10] = "abcdef";
    char arr2[] = "hello bit";
    strncpy(arr1, arr2, 4);
    printf("%s\n", arr1); //hellef \0

    char arr3[10] = "abcdef";
    char arr4[] = "bit";
    strncpy(arr3, arr4, 6);
    printf("%s\n", arr3); //b i t 0 0 0 0 0 0 0
}
int main()
{
    test1(); //strncpy����
    test2(); //strncat����
    test3(); //strncmp����
    return 0;
}
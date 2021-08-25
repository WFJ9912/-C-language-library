#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>

int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int test1()
{
	/*
	size_t strlen ( const char * str );
	1.字符串以 '\0' 作为结束标志，strlen函数返回的是在字符串中 '\0' 前面出现的字符个数（不包含 '\0' )。
	2.参数指向的字符串必须要以 '\0' 结束。
	3.注意函数的返回值为size_t，是无符号的（ 易错 ）
	4.学会strlen函数的模拟实现
	*/
	int len1 = strlen("abcd");
	int len2 = my_strlen("abcde");

	printf("%d\n", len1);//4
	printf("%d\n", len2);//5
}



char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//拷贝src指向的字符串到dest指向的空间
	while (*dest++ = *src++)
	{
		;
	}
	//返回目的空间的起始地址
	return ret;
}
int test2()
{
	/*
	    char* strcpy(char * destination, const char * source );
	    1.Copies the C string pointed by source into the array pointed by destination, including the terminating null character(and stopping at that point).
		2.源字符串必须以 '\0' 结束。
		3.会将源字符串中的 '\0' 拷贝到目标空间。
		4.目标空间必须足够大，以确保能存放源字符串。
		5.目标空间必须可变。
		6.学会模拟实现。
	*/
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";

	char arr3[] = "abcdefghi";
	char arr4[] = "bit";

	strcpy(arr1, arr2);
	my_strcpy(arr3, arr4);

	printf("%s\n", arr1);//bit
	printf("%s\n", arr3);//bit
}



char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != '\0');
	assert(src);
	//1.找到目标字符串的'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.追加
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int test3()
{
	/*
	char * strcat ( char * destination, const char * source );
	1.Appends a copy of the source string to the destination string.The terminating null character in destination is overwritten by the first character of source, and a null - character is included at the end of the new string formed by the concatenation of both in destination.
	2.源字符串必须以 '\0' 结束。
	3.目标空间必须有足够的大，能容纳下源字符串的内容。
	4.目标空间必须可修改。
	5.字符串自己给自己追加，如何？--崩溃，死循环
	*/
	char arr1[30] = "hello ";
	char arr2[] = "world";

	char arr3[30] = "hello ";
	char arr4[] = "world";

	strcat(arr1, arr2);
	my_strcat(arr3, arr4);
	printf("%s\n", arr1);//hello world

	printf("%s\n", arr3);//hello world
}

int main()
{
	test1();//strlen函数
	test2();//strcpy函数
	test3();//strcat函数
	return 0;
}
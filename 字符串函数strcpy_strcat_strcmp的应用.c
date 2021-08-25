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
	1.�ַ����� '\0' ��Ϊ������־��strlen�������ص������ַ����� '\0' ǰ����ֵ��ַ������������� '\0' )��
	2.����ָ����ַ�������Ҫ�� '\0' ������
	3.ע�⺯���ķ���ֵΪsize_t�����޷��ŵģ� �״� ��
	4.ѧ��strlen������ģ��ʵ��
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
	//����srcָ����ַ�����destָ��Ŀռ�
	while (*dest++ = *src++)
	{
		;
	}
	//����Ŀ�Ŀռ����ʼ��ַ
	return ret;
}
int test2()
{
	/*
	    char* strcpy(char * destination, const char * source );
	    1.Copies the C string pointed by source into the array pointed by destination, including the terminating null character(and stopping at that point).
		2.Դ�ַ��������� '\0' ������
		3.�ὫԴ�ַ����е� '\0' ������Ŀ��ռ䡣
		4.Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ�����
		5.Ŀ��ռ����ɱ䡣
		6.ѧ��ģ��ʵ�֡�
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
	//1.�ҵ�Ŀ���ַ�����'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.׷��
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
	2.Դ�ַ��������� '\0' ������
	3.Ŀ��ռ�������㹻�Ĵ���������Դ�ַ��������ݡ�
	4.Ŀ��ռ������޸ġ�
	5.�ַ����Լ����Լ�׷�ӣ���Σ�--��������ѭ��
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
	test1();//strlen����
	test2();//strcpy����
	test3();//strcat����
	return 0;
}
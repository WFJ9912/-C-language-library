#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
	char arr1[] = "welcome to bit!!!!!!";
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1)-1;
	while(left<right)
	{
		printf("%s\n", arr2);
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		//��Ϣ1��
		Sleep(1000);
		system("cls");//ִ��ϵͳ�����һ������-cls-�����Ļ
		left++;
		right--;
	}
	return 0;
}
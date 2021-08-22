#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


struct Stu
{
	char name[20];
	int age;
};



int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void*e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=���Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
//ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ���������������-��֪��
//�ǳ���ԱҲ��֪�������Ƚϵ�����Ԫ�ص�����

void Swap(char* buf1, char*buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void*base, int sz, int width, int (*cmp)(void*e1,void*e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		int i=0;
		//ÿһ�˱ȽϵĶ���
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			//����Ԫ�صıȽ�
			if (cmp((char*)base+j*width, (char*)base+(j+1)*width) > 0)
			{
				//����
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}


void test5()
{
	struct Stu s[3] = { { "zhangsan", 20 }, { "lisi", 30 }, { "wangwu", 10 } };
	int sz = sizeof(s) / sizeof(s[0]);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int l = 0;
	for (l = 0; l < sz; l++)
	{
		printf("name=%s age=%d    ", s[l].name, s[l].age);
	}
}

int main()
{
	test5();
	return 0;
}

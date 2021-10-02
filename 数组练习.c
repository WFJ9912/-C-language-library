#include <stdio.h>

#define N [10]

typedef  int Datatype;

int i;

typedef struct Sqlist
{
	Datatype arr N;
	int size;
}Sqlist;


void test1(Sqlist* ps)
{
	int left = 0, right = ps->size - 1;
	while (left < right)
	{
		while (ps->arr[left] < 0)
		{
			left++;
		}
		while (ps->arr[right] >= 0)
		{
			right--;
		}
		ps->arr[left] = (ps->arr[left]) ^ (ps->arr[right]);
		ps->arr[right] = (ps->arr[left]) ^ (ps->arr[right]);
		ps->arr[left] = (ps->arr[left]) ^ (ps->arr[right]);
	}
	ps->arr[left] = (ps->arr[left]) ^ (ps->arr[right]);
	ps->arr[right] = (ps->arr[left]) ^ (ps->arr[right]);
	ps->arr[left] = (ps->arr[left]) ^ (ps->arr[right]);

}
void test2(Sqlist* ps)
{
	int src = 0, dst = 0;
	Datatype max = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] > max)
		{
			max = ps->arr[i];
		}
	}
	while (src < ps->size)
	{
		if (ps->arr[src] != max)
		{
			ps->arr[dst] = ps->arr[src];
			src++;
			dst++;
		}
		else
		{
			++src;
		}
	}
	ps->size = dst;
}
void test3(Sqlist* ps, Sqlist* copyps)
{
	copyps->arr;
	copyps->size = 0;

	int src = 0, dst = 0;
	while (src < ps->size)
	{
		//Datatype tmp = (ps->arr[src]) / 2;
		if ((ps->arr[src]) % 2 != 0)
		{
			ps->arr[dst] = ps->arr[src];
			++dst;
			++src;
		}
		else
		{
			int i = 0;
			copyps->arr[copyps->size] = ps->arr[src];
			copyps->size++;
			src++;
		}
	}
	ps->size = dst;

}
int main()
{

	//= { 1, 2, -1, 3, 0, 1, 2, -5, -4, 3 };
	Sqlist s,s1;
	s.arr[0] = 21, s.arr[1] = 2, s.arr[2] = -7, s.arr[3] = 0, s.arr[4] = 21, s.arr[5] = 5, s.arr[6] = 0;
	s.size = 7;
	printf("ԭ���飺");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//����һ��˳���L������Ԫ��Ϊ���������һ���㷨������˳���ʹ��������С��0��Ԫ���ƶ������д��ڵ���0��Ԫ�ص�ǰ�档
	test1(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//��һ���������У�����˳���L�洢����ƽ����ܸ�Ч���㷨ɾ��L�����ֵ��Ԫ�أ�����������Ԫ���ж������
	test2(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//����һ��˳���L����Ԫ�ؾ�Ϊ�����������һ���㷨��L������ż��ɾ�����浽��һ��˳���L1�У���˳���L����ԭ��������������
	test3(&s,&s1);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");
	for (i = 0; i < s1.size; i++)
		printf("%d ", s1.arr[i]);
	return 0;
}

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


void quicksort(Sqlist *ps,int s1, int s2)
{
	if (s1 < s2) 
	{
		int i, j, x;
		i = s1;
		j = s2;
		x = ps->arr[i];

		while (i < j)
		       {
			            while (i < j && ps->arr[j] > x)
				               j--; // ���������ҵ�һ��С��x����
			            if (i < j)
				               ps->arr[i++] = ps->arr[j];
			             while (i < j && ps->arr[i] < x)
				                i++; // ���������ҵ�һ������x����
			           if (i < j)
				                 ps->arr[j--] = ps->arr[i];
			        }
		
			ps->arr[i] = x;
		
			quicksort(ps, s1, i - 1); /* �ݹ���� */
			quicksort(ps, i + 1, s2);

	}
}

void Delrepeat(Sqlist* ps)
{
	int prev = 0, cur = 1, dst = 0;
	int t = ps->size;
	while (cur<t)
	{
		if (ps->arr[prev] == ps->arr[cur])
		{
			prev++;
			cur++;
		}
		else
		{
			ps->arr[dst] = ps->arr[prev];
			prev++;
			cur++;
			dst++;
		}
	}
	ps->arr[dst] = ps->arr[prev];
	dst++;
	prev++;
	ps->size = dst;
}
void test4(Sqlist* ps)
{
	int left = 0, right = ps->size - 1;
	quicksort(ps,left, right);
	Delrepeat(ps);
}

void test5(Sqlist* ps)
{
	Delrepeat(ps);

}
int main()
{

	//= { 1, 2, -1, 3, 0, 1, 2, -5, -4, 3 };
	Sqlist s,s1;
	s.arr[0] = 5, s.arr[1] = 8, s.arr[2] = 7, s.arr[3] = 2, s.arr[4] = 6, s.arr[5] = 9, s.arr[6] = 5;
	s.size = 7;
	printf("ԭ���飺");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//����һ��˳���L������Ԫ��Ϊ���������һ���㷨������˳���ʹ��������С��0��Ԫ���ƶ������д��ڵ���0��Ԫ�ص�ǰ�档
	printf("��Ŀ1��");
	test1(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");


	//��һ���������У�����˳���L�洢����ƽ����ܸ�Ч���㷨ɾ��L�����ֵ��Ԫ�أ�����������Ԫ���ж������
	printf("��Ŀ2��");
	test2(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");


	//����һ��˳���L����Ԫ�ؾ�Ϊ�����������һ���㷨��L������ż��ɾ�����浽��һ��˳���L1�У���˳���L����ԭ��������������
	printf("��Ŀ3��������");
	test3(&s,&s1);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n\tż����");
	for (i = 0; i < s1.size; i++)
		printf("%d ", s1.arr[i]);
	printf("\n");


	//���һ���㷨��˳�����ɾ���ظ���Ԫ�أ����ֵ��ͬ��Ԫ�ؽ�����һ����
	test4(&s);
	printf("��Ŀ4��");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//���һ���㷨������˳�����ɾ���ظ���Ԫ�أ����ֵ��ͬ��Ԫ�ؽ�����һ����
	test5(&s);
	printf("��Ŀ5��");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");
	return 0;
}

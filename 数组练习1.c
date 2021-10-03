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
				               j--; // 从右向左找第一个小于x的数
			            if (i < j)
				               ps->arr[i++] = ps->arr[j];
			             while (i < j && ps->arr[i] < x)
				                i++; // 从左向右找第一个大于x的数
			           if (i < j)
				                 ps->arr[j--] = ps->arr[i];
			        }
		
			ps->arr[i] = x;
		
			quicksort(ps, s1, i - 1); /* 递归调用 */
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
	printf("原数组：");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//假设一个顺序表L中所有元素为整数，设计一个算法调整该顺序表，使其中所有小于0的元素移动到所有大于等于0的元素的前面。
	printf("题目1：");
	test1(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");


	//有一个整数序列，采用顺序表L存储。设计近可能高效的算法删除L中最大值的元素（假设这样的元素有多个）。
	printf("题目2：");
	test2(&s);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");


	//设有一个顺序表L，其元素均为正整数，设计一个算法将L中所有偶数删除并存到另一个顺序表L1中，而顺序表L保留原来的所有奇数。
	printf("题目3：奇数：");
	test3(&s,&s1);
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n\t偶数：");
	for (i = 0; i < s1.size; i++)
		printf("%d ", s1.arr[i]);
	printf("\n");


	//设计一个算法从顺序表中删除重复的元素，多个值相同的元素仅保留一个。
	test4(&s);
	printf("题目4：");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");

	//设计一个算法从有序顺序表中删除重复的元素，多个值相同的元素仅保留一个。
	test5(&s);
	printf("题目5：");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.arr[i]);
	printf("\n");
	return 0;
}

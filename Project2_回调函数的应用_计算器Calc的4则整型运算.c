#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu()
{
	printf("**********************\n");
	printf("**   1:Add   2.Sub  **\n");
	printf("**   3:Mul   4.Div  **\n");
	printf("**        0.exit    **\n");
	printf("**********************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int calc(int (*pa)(int,int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数：>");
	scanf("%d %d", &x, &y);
	printf("%d\n", (*pa)(x, y));
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
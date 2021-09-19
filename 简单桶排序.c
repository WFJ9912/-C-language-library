#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main()
{
    //简单通排序-输入数字0-9范围内-10个数字由小到大排序 
    int arr[10], i, j, t;
    for ( i = 0; i < 10; i++)//初始化10个变量 
        arr[i] = 0;
    for ( i = 1; i <= 10; ++i)//这些变量放在数组的下标中，并进行统计 
    {
        int t = 0;
        scanf("%d", &t);
        arr[t]++;
    }
    for ( i = 0; i <= 10; i++)//从下标0开始打印 ，由小到大排序 
    {
        for (j = 1; arr[i] >= j; ++j)// 出现了几次就打印几次 
            printf("%d ", i);
    }
    system("pause");
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#define Typenums int
#include <stdio.h>
#include <stdlib.h>

int a[101], n;//定义全局变量，这两个变量需要在子函数中使用-快速排序

void test1()
{
    int arr[100], i, n, t, j;
    for (i = 0; i < 100; i++) //初始化
    {
        arr[i] = 0;
    }
    scanf("%d", &n); //输入要排序的个数n，0<=n<=100;
    for (i = 0; i < n; i++)//以数组下标进行标记
    {
        int t = 0;
        scanf("%d", &t);//输入可排序的整数为0-99，个数由arr决定
        arr[t]++;
    }
    for (i = 0; i < 100; i++)//遍历数组,由小到大,若由大到小可以改为for (i = 100; i >= 0; i--)
    {
        for (j = 1; arr[i] >= j; ++j)//如果数组的值为1，则出现1次，打印该数组下标，以此类推
            printf("%d ", i);//注意
    }

}

void test2()
{
    int n, i, t, j;
    scanf("%d", &n);//输入要排序的个数
    int* pa = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        int t = 0;
        scanf("%d", &t);//输入可排序的任意整数，注意int的范围，个数由arr决定
        pa[i] = t;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (pa[j] > pa[j + 1])//由小到大排序，若由大到小可以改为pa[j] < pa[j + 1]
            {
                int tmp = 0;//交换
                tmp = pa[j];
                pa[j] = pa[j + 1];
                pa[j + 1] = tmp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", pa[i]);
    }
    free(pa);
    pa = NULL;
}


void quicksort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;


    temp = a[left];//temp中存的就是基准数
    i = left;
    j = right;
    while (i != j)
    {
        //顺序很重要，首先从右往左找
        while (a[j] >= temp && i < j)
            j--;
        //再从左往右找
        while (a[i] <= temp && i < j)
            i++;

        //交换两个数在数组中的位置
        if (i < j)//当哨兵i和哨兵j没有相遇是
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1);//继续处理左边的，这是一个递归的过程
    quicksort(i + 1, right);//继续处理右边的，这是一个递归的过程
}

void test3()
{
    int i,n,j,  tmp;
    scanf("%d", &n);//输入要排序的个数
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);//输入可排序的任意整数，注意int的范围，个数由a决定
    }
    quicksort(1,n);
    for (i =1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

}
int main()
{
    //test1(); //桶排序
    //test2();//冒泡排序
    test3();//快速排序
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#define Typenums int
#include <stdio.h>
#include <stdlib.h>

int a[101], n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��-��������

void test1()
{
    int arr[100], i, n, t, j;
    for (i = 0; i < 100; i++) //��ʼ��
    {
        arr[i] = 0;
    }
    scanf("%d", &n); //����Ҫ����ĸ���n��0<=n<=100;
    for (i = 0; i < n; i++)//�������±���б��
    {
        int t = 0;
        scanf("%d", &t);//��������������Ϊ0-99��������arr����
        arr[t]++;
    }
    for (i = 0; i < 100; i++)//��������,��С����,���ɴ�С���Ը�Ϊfor (i = 100; i >= 0; i--)
    {
        for (j = 1; arr[i] >= j; ++j)//��������ֵΪ1�������1�Σ���ӡ�������±꣬�Դ�����
            printf("%d ", i);//ע��
    }

}

void test2()
{
    int n, i, t, j;
    scanf("%d", &n);//����Ҫ����ĸ���
    int* pa = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        int t = 0;
        scanf("%d", &t);//��������������������ע��int�ķ�Χ��������arr����
        pa[i] = t;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (pa[j] > pa[j + 1])//��С�����������ɴ�С���Ը�Ϊpa[j] < pa[j + 1]
            {
                int tmp = 0;//����
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


    temp = a[left];//temp�д�ľ��ǻ�׼��
    i = left;
    j = right;
    while (i != j)
    {
        //˳�����Ҫ�����ȴ���������
        while (a[j] >= temp && i < j)
            j--;
        //�ٴ���������
        while (a[i] <= temp && i < j)
            i++;

        //�����������������е�λ��
        if (i < j)//���ڱ�i���ڱ�jû��������
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //���ս���׼����λ
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1);//����������ߵģ�����һ���ݹ�Ĺ���
    quicksort(i + 1, right);//���������ұߵģ�����һ���ݹ�Ĺ���
}

void test3()
{
    int i,n,j,  tmp;
    scanf("%d", &n);//����Ҫ����ĸ���
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);//��������������������ע��int�ķ�Χ��������a����
    }
    quicksort(1,n);
    for (i =1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

}
int main()
{
    //test1(); //Ͱ����
    //test2();//ð������
    test3();//��������
    return 0;
}

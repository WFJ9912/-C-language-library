#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main()
{
    //��ͨ����-��������0-9��Χ��-10��������С�������� 
    int arr[10], i, j, t;
    for ( i = 0; i < 10; i++)//��ʼ��10������ 
        arr[i] = 0;
    for ( i = 1; i <= 10; ++i)//��Щ��������������±��У�������ͳ�� 
    {
        int t = 0;
        scanf("%d", &t);
        arr[t]++;
    }
    for ( i = 0; i <= 10; i++)//���±�0��ʼ��ӡ ����С�������� 
    {
        for (j = 1; arr[i] >= j; ++j)// �����˼��ξʹ�ӡ���� 
            printf("%d ", i);
    }
    system("pause");
    return 0;
}

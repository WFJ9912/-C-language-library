#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Stu 10//����10��ѧ���������

//���⣺��ʦ��һ�����飬����ÿ��ѧ��ϲ��ʲô�飬��ͳ�����ISBN�ţ�����ISBN��Ϊ��������Ȼ��Щ������кܶ�ͬѧϲ����
//��ʦҪȥ���ظ���ISBN�ţ�������С����������ȥ�������
int main()
{
    int n = 0, i,  k, t;
    int* pa = (int*)malloc(sizeof(int) * Stu);
    for (i = 0; i < Stu; i++)
    {
        scanf("%d", &pa[i]);
    }
    for (i = 0; i < Stu - 1; i++)
    {
        for (k = 0; k < Stu - i - 1; k++)
        {
            if (pa[k] > pa[k + 1])
            {
                int tmp = 0;
                tmp = pa[k];
                pa[k] = pa[k + 1];
                pa[k + 1] = tmp;
            }
        }
    }
    for (t = 0; t < Stu; t++)
    {
           if(pa[t]!=pa[t+1])
            printf("%d ", pa[t]);

    }
    free(pa);
    pa = NULL;
    return 0;
}

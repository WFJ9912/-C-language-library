#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Stu 10//假设10个学生参与调查

//问题：老师做一个调查，看看每个学生喜欢什么书，并统计书的ISBN号，假设ISBN号为整数，当然有些好书会有很多同学喜欢，
//老师要去掉重复的ISBN号，并按从小到达排序，再去书店买书
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

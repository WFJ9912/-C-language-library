#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct zhan
{
    char* arr;
    int top;
}zhan;

void zhanInsert(zhan* pa)
{
    pa->arr = (char*)malloc(sizeof(char) * 50);
    if (pa->arr == NULL)
    {
        exit(-1);
    }
    pa->top = 0;
}

void zhanRead(zhan* pa)
{
    char s[100];
    int i, next;
    gets(s);//����һ���ַ���
    int len = strlen(s);//���ַ����ĳ���
    int mid = len / 2 - 1;//���ַ������յ�

    //��midǰ���ַ�������mid������ջ
    for (i = 0; i <= mid; i++)
    {

        pa->arr[++(pa->top)] = s[i];
    }
    //�ж��ַ����ĳ�������������ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
    if (len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }
    //��ʼƥ��
    for (i = next; i <=len - 1; i++)
    {
        if (pa->arr[pa->top] != s[i])
            break;
        pa->top = pa->top - 1;
    }
    //���top��ֵΪ0����˵��ջ�������ַ�����һһƥ����
    if (pa->top == 0)
        printf("YES\n");
    else
        printf("NO\n");

}
int main()
{

    //ջ��Ӧ��-������-�жϻ����ַ�����xyzyx��
    zhan a;
    zhanInsert(&a);//��ʼ��
    zhanRead(&a);//�����ַ����ж�
    free(a.arr);
    a.arr = NULL;

    return 0;
}

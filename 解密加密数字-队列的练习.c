#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#define MAX 9 //������ܵ�����Ϊ9λ����

typedef struct queue
{
    int* data;//����
    int head;
    int tail;
}queue;

void queueInsert(queue* ps)
{
    ps->data = (int*)malloc(sizeof(int) * MAX*10);
    if (ps == NULL)
    {
        exit(-1);
    }
    else
    {
        ps->head = 0;
        ps->tail = 0;
    }
}
void queuefunc(queue* ps)
{
    int i;
    int start = ps->head;
    int end = ps->tail;
    ++end;
    for (i = 0; i < MAX; i++)
    {
        //��ӡ���ײ������׳���
        printf("%d", ps->data[start]);
        start++;
        //���¶��׵�����ӵ���β
        ps->data[end] = ps->data[start];
        end++;
        //�ٽ����׳���
        start++;
    }
    ps->tail = end;
    ps->head = start;
}

void queuePrint(queue* ps, int t)
{
    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &ps->data[i]);
        ps->tail = i;
    }
}
int main()
{
    //����-�Ƚ��ȳ�
    //�����ܹ������ֽ���-���Ƚ����ܵĵ�һ����ɾ���������Ž��ڶ������ŵ�ĩβ���Դ����ƣ�ֱ�����һ����Ҳɾ�������ող�ɾ����˳������һ�����ԭ�ܡ�
    queue nums;
    queueInsert(&nums);//��ʼ��
    queuePrint(&nums, MAX);//¼����ܵ�����
    queuefunc(&nums);//����
    free(nums.data);
    nums.data = NULL;

    return 0;
}

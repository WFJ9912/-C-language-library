#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#define MAX 9 //假设加密的密码为9位整数

typedef struct queue
{
    int* data;//队列
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
        //打印队首并将队首出列
        printf("%d", ps->data[start]);
        start++;
        //将新队首的数添加到队尾
        ps->data[end] = ps->data[start];
        end++;
        //再将队首出队
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
    //队列-先进先出
    //将加密过的数字解密-首先将加密的第一个数删除，紧接着将第二个数放到末尾，以此类推，直到最后一个数也删除。按照刚才删除的顺序连在一起就是原密、
    queue nums;
    queueInsert(&nums);//初始化
    queuePrint(&nums, MAX);//录入加密的密码
    queuefunc(&nums);//解密
    free(nums.data);
    nums.data = NULL;

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#define x 6   //假设小明有6张牌
#define y 6   //假设小红有6张牌


//纸牌游戏：将一副扑克牌平均分成两份，每人拿一份。小明先拿出手中的第一张扑克牌放在桌子上，然后小红也拿出手中的第一张扑克牌，并放在小明刚打出的扑克牌的上面，就像这样两人交替出牌。
// 出牌时，如果某人打出的牌与桌子上某张牌的牌面相同，即可将两张相同的牌及其中间所夹的牌全部取走，并依次放到自己手中牌的末尾。当任意一人手中的牌全部出完时，游戏结束，对手获胜。
// 分析：我们需要两个队列，一个栈来模拟整个游戏
//队列
typedef struct queue
{
    int data[1000];
    int head;
    int tail;
}queue;

//栈
typedef struct stack
{
    int data[10];
    int top;
}stack;


int main()
{
    queue q1, q2;
    stack s;
    int book[10];
    int i, t;
    //初始化队列和栈
    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    s.top = 0;

    for (i = 1; i <= 9; i++)
    {
        book[i] = 0;
    }

    for (i = 1; i <= x; i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }

    for (i = 1; i <= y; i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }

    while (q1.head < q1.tail && q2.head < q2.tail)
    {
        t = q1.data[q1.head];
        if (book[t] == 0)
        {
            q1.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
        }
        t = q2.data[q2.head];
        if (book[t] == 0)
        {
            q2.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while (s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
    }
    if (q2.head == q2.tail)
    {
        printf("小明Win\n");
        printf("小明手中的牌是");
        for (i = q1.head; i <= q1.tail - 1; i++)
            printf(" %d", q1.data[i]);
        if (s.top > 0)
        {
            printf("\n桌上的牌是");
            for (i = 1; i <= s.top; i++)
                printf(" %d", s.data[i]);
        }
        else
            printf("\n桌上已经没拍了");
    }
    else
    {
        printf("小红Win\n");
        printf("小明红中的牌是");
        for (i = q2.head; i <= q2.tail - 1; i++)
            printf(" %d", q2.data[i]);
        if (s.top > 0)
        {
            printf("\n桌上的牌是");
            for (i = 1; i <= s.top; i++)
                printf(" %d", s.data[i]);
        }
        else
            printf("\n桌上已经没拍了");
    }



    return 0;
}

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
    gets(s);//读入一行字符串
    int len = strlen(s);//求字符串的长度
    int mid = len / 2 - 1;//求字符串的终点

    //将mid前的字符串包括mid依次入栈
    for (i = 0; i <= mid; i++)
    {

        pa->arr[++(pa->top)] = s[i];
    }
    //判断字符串的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
    if (len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }
    //开始匹配
    for (i = next; i <=len - 1; i++)
    {
        if (pa->arr[pa->top] != s[i])
            break;
        pa->top = pa->top - 1;
    }
    //如果top的值为0，则说明栈内所有字符都被一一匹配了
    if (pa->top == 0)
        printf("YES\n");
    else
        printf("NO\n");

}
int main()
{

    //栈的应用-后进后出-判断回文字符串“xyzyx”
    zhan a;
    zhanInsert(&a);//初始化
    zhanRead(&a);//读入字符并判断
    free(a.arr);
    a.arr = NULL;

    return 0;
}

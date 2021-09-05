#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void test2()
{
    /*
    什么是位段-位段的声明和结构是类似的，有两个不同：
    1.位段的成员必须是int，unsigned int或signed int。（通常都是相同类型）
    2.位段的成员名后边有一个冒号和数字
    */
    struct T
    {
        int _a : 2;
        int _b : 5;
        int _c : 10;
        int _d : 30;
    };
    struct T t = {0};
    printf("%d\n",sizeof(t));//8
    struct C
    {
        char a : 3;
        char b : 4;
        char c : 5;
        char d : 4;
    };
    struct C c = {0};
    c.a = 10;
    c.b = 20;
    c.c = 3;
    c.d = 4;
    //最终内存显示为22 03 04
    //总结：跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但有跨平台问题的存在。
    //位段一般用于网络上的数据传输
}

void test1()
{
    //结构体传参的时候要传结构体的地址。
    //函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。当结构体过大会导致性能的下降
    struct S
    {
        int a;
        char c;
        double d;
    };

    void Inits(struct S * ps)
    {
        ps ->a = 100;
        ps ->c = 'w';
        ps ->d = 3.14;
    }

    void Print2(const struct S *ps)
    {
        printf("%d %c %lf\n", ps->a, ps->c, ps->d); //100 w 3.14
    }

    struct S s = {0};
    Inits(&s);
    Print2(&s);
}
int main()
{
    test1(); //结构体传参
    test2(); //位段
    return 0;
}
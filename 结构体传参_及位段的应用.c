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
    ʲô��λ��-λ�ε������ͽṹ�����Ƶģ���������ͬ��
    1.λ�εĳ�Ա������int��unsigned int��signed int����ͨ��������ͬ���ͣ�
    2.λ�εĳ�Ա�������һ��ð�ź�����
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
    //�����ڴ���ʾΪ22 03 04
    //�ܽ᣺���ṹ��ȣ�λ�ο��Դﵽͬ����Ч�������ǿ��ԺܺõĽ�ʡ�ռ䣬���п�ƽ̨����Ĵ��ڡ�
    //λ��һ�����������ϵ����ݴ���
}

void test1()
{
    //�ṹ�崫�ε�ʱ��Ҫ���ṹ��ĵ�ַ��
    //�������ε�ʱ�򣬲�������Ҫѹջ������ʱ��Ϳռ��ϵ�ϵͳ���������ṹ�����ᵼ�����ܵ��½�
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
    test1(); //�ṹ�崫��
    test2(); //λ��
    return 0;
}
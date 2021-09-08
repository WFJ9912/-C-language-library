#include <stdio.h>

void test1() 
{
    int a = 1;
    if(1 == *(char*)&a)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
}


int check_sys()
{
    int a = 1;
    return *(char*)&a;
}
void test2() 
{
    int a = 1;
    int ret = check_sys();
    if(1 == ret)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
}


int check_sys2()
{
    union Un
    {
        char c;
        int i;
    }u;
    u.i = 1;//返回1表示小端
    return u.c;
}
void test3()
{
    int a = 1;
    int ret = check_sys2();
    if(1 == ret)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
}
int main()
{
    //判断大小端字节序问题的三个方法
    test1();
    test2();
    test3();
    return 0;
}
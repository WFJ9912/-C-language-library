#include <stdio.h>

void test1() 
{
    int a = 1;
    if(1 == *(char*)&a)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
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
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }
}


int check_sys2()
{
    union Un
    {
        char c;
        int i;
    }u;
    u.i = 1;//����1��ʾС��
    return u.c;
}
void test3()
{
    int a = 1;
    int ret = check_sys2();
    if(1 == ret)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }
}
int main()
{
    //�жϴ�С���ֽ����������������
    test1();
    test2();
    test3();
    return 0;
}
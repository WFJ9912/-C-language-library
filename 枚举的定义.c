#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

enum Day//DayΪö������
{
    Mon,
    Tues,
    Wed,
    Thur = 4,
    Fri,
    Sat,
    Sun
    //ö�ٵĿ���ȡֵ��ö�ٳ���
    //��Щ����ȡֵ������ֵ�ģ�Ĭ�ϴ�0��ʼ��һ�ε���1����Ȼ�ڶ����ʱ��Ҳ���Ը���ֵ
};

int main()
{
    //ö�����͵Ķ���
    enum Day d = Mon;
    printf("%d %d %d %d %d %d %d\n", Mon,Tues,Wed,Thur,Fri,Sat,Sun);//0 1 2 4 5 6 7
    //ö�ٵ��ŵ�
    /*
    1.���Ӵ���Ŀɶ��ԺͿ�ά����
    2.��#define����ı�ʶ���Ƚϣ�ö�������ͼ�飬�����Ͻ���
    3.��ֹ��������Ⱦ����װ��
    4.���ڵ���
    5.ʹ�÷��㣬һ�ο��Զ���������    
    */
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

enum Day//Day为枚举类型
{
    Mon,
    Tues,
    Wed,
    Thur = 4,
    Fri,
    Sat,
    Sun
    //枚举的可能取值，枚举常量
    //这些可能取值都是有值的，默认从0开始，一次递增1，当然在定义的时候也可以赋初值
};

int main()
{
    //枚举类型的定义
    enum Day d = Mon;
    printf("%d %d %d %d %d %d %d\n", Mon,Tues,Wed,Thur,Fri,Sat,Sun);//0 1 2 4 5 6 7
    //枚举的优点
    /*
    1.增加代码的可读性和可维护性
    2.和#define定义的标识符比较，枚举有类型检查，更加严谨。
    3.防止了命名污染（封装）
    4.便于调试
    5.使用方便，一次可以定义多个变量    
    */
}
#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<time.h>

clock_t start,stop;
//clock_t是clock（)函数返回的变量类型
double duration;
int main()
{//不在测试范围内的准备工作写在clock（）调用之前
    start = clock();//开始计时
    //MyFunction();//把被测函数加在这里
    stop = clock();//停止计时
    duration = ((double)(stop - start));
    //其它不在测试范围的处理写在后面，例如输出duration的值
    printf( "%2.1f seconds\n", duration );
}

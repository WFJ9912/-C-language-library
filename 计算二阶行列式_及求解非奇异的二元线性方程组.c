#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void menu()
{
    printf("********************************\n");
    printf("** 1.�����������ʽ   0.�˳�  **\n");
    printf("** 2.��������Ķ�Ԫ���Է����� **\n");
    printf("*******************************\n");
}
int calc(double(*pa)(double,double,double,double))
{
    double arr[4] = {0};
    printf("************\n");
    printf("|  0     1 |\n");
    printf("|  2     3 |\n");
    printf("************\n");
    printf("�������ĸ����������ֱ��Ӧ0 1 2 3����>");
    scanf("%lf %lf %lf %lf", arr,arr+8,arr+16,arr+24);
    printf("************\n");
    printf("|  %lf     %lf |\n", *arr, *(arr + 8));
    printf("|  %lf     %lf |\n", *(arr + 16), *(arr + 24));
    printf("************\n");
    printf("��������ʽ���Ϊ%lf\n", (*pa)(*arr,*(arr+8),*(arr+16),*(arr+24)));
}
double Ejhls(double q,double w,double e,double r)
{
    return q*r-e*w;
}
int calc2(double(*pa)(double,double,double,double))
{
    int D = 0;
    int D1 = 0;
    int D2 = 0;
    double arr[] = {0};
    printf("************\n");
    printf("aX1 + bX2 = e\n");
    printf("cX3 + dX4 = f\n");
    printf("************\n");
    printf("����������������(�ֱ��Ӧa b c d e f)��>");
    scanf("%lf %lf %lf %lf %lf %lf", arr,arr+8,arr+16,arr+24,arr+32,arr+40);
    if((*pa)(*arr,*(arr+8),*(arr+16),*(arr+24)) == 0)
    {
        printf("����\n");
        return 0;
    }
    else
    {
        double D = (*pa)(*arr,*(arr+8),*(arr+16),*(arr+24)); 
        double D1 = (*pa)(*(arr+32),*(arr+8),*(arr+40),*(arr+24));
        double D2 = (*pa)(*arr,*(arr+32),*(arr+16),*(arr+40));
        printf("X1=%lf X2=%lf",D1/D,D2/D);
    }
}
int main()
{
    int input = 0;
    do
    {
    menu();
    printf("��ѡ��>");
    scanf("%d", &input);
    
    switch (input)
    {
    case 1:
        calc(Ejhls);
        break;
    case 2:
        calc2(Ejhls);
        break;
    case 0:
        printf("�˳�\n");
        break;
    default:
        printf("ѡ�����\n");
        break;
    }
    }
    while (input);
    return 0;
}
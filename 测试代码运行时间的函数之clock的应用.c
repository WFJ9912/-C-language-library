#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<time.h>

clock_t start,stop;
//clock_t��clock��)�������صı�������
double duration;
int main()
{//���ڲ��Է�Χ�ڵ�׼������д��clock��������֮ǰ
    start = clock();//��ʼ��ʱ
    //MyFunction();//�ѱ��⺯����������
    stop = clock();//ֹͣ��ʱ
    duration = ((double)(stop - start));
    //�������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ
    printf( "%2.1f seconds\n", duration );
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>
void test1()
{
    /*
    size_t offsetof(structName,memberName);
    ����ṹ���Ա����ڽṹ����ʼλ�õ�ƫ�����Ƕ���
    offsetof���Ǻ����Ǻ�
    */
    struct T 
    {
        char c;
        int i;
        double d;
    };
    printf("%d\n",offsetof(struct T,c));//0
    printf("%d\n",offsetof(struct T,i));//4
    printf("%d\n",offsetof(struct T,d));//8
}
//����Ĭ�϶�����Ϊ4
#pragma pack(4)
struct S 
{
    char c1;//1
    //3
    double d;//8 4 4
};
#pragma pack()
//ȡ�����õ�Ĭ�϶�����
int main()
{
    //�ṹ��֮�޸�Ĭ�϶�����
    struct S s;
    printf("%d\n",sizeof(s));//12
    test1();//offseto��Ӧ��
    return 0;
}
//���ۣ��ṹ�ڶ��뷽ʽ�����ʵ�ʱ�����ǿ����Լ�����Ĭ�϶�������
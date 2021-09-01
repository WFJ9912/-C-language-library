#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

struct T
{
    double weight;
    short age;
};
struct S
{
    char c;
    struct T st;
    int a;
    double d;
    char arr[20];
};


typedef struct Node
{
    int data;
    struct Node *next;
}Node;


int main()
{
    //结构体的定义和初始化
    struct S s = {'c', {55.6, 30}, 100, 3.14, "hello bit"};
    printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);//c 100 3.140000 hello bit
    printf("%lf\n", s.st.weight);//55.600000

    
    //结构体的自引用
    struct Node *n1;
    Node n2;
    return 0;
}
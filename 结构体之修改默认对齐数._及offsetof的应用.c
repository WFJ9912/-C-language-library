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
    计算结构体成员相对于结构体起始位置的偏移量是多少
    offsetof不是函数是宏
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
//设置默认对齐数为4
#pragma pack(4)
struct S 
{
    char c1;//1
    //3
    double d;//8 4 4
};
#pragma pack()
//取消设置的默认对齐数
int main()
{
    //结构体之修改默认对齐数
    struct S s;
    printf("%d\n",sizeof(s));//12
    test1();//offseto的应用
    return 0;
}
//结论：结构在对齐方式不合适的时候，我们可以自己更改默认对齐数。
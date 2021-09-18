#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct S
{
    int n;
    int arr[]; //或arr[0],未知大小的-柔性数组成员-数组的大小是可以调整的
};
struct T
{
    int n;
    int *arr;
};

void test1()
{
    //
    //
    struct S s;
    printf("%d\n", sizeof(s));
    struct S *ps = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
    if (ps == NULL)
    {
        printf("%s", strerror(errno));
        exit(-1);
    }
    ps->n = 100;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ps->arr[i] = i; //0 1 2 3 4
    }
    struct S *ptr = realloc(ps, 44);
    if (ptr != NULL)
    {
        ps = ptr;
    }
    for (i = 5; i < 10; i++)
    {
        ps->arr[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d", ps->arr[i]); //0 1 2 3 4 5 6 7 8 9
    }
    printf("\n");
    free(ps);
    ps = NULL;
}

void test2()
{
    struct T t;
    printf("%d", sizeof(t));
    printf("\n");
    struct T *ps = (struct T *)malloc(sizeof(struct T));
    ps->arr = malloc(5 * sizeof(int));
    if (ps == NULL)
    {
        printf("%s", strerror(errno));
        exit(-1);
    }
    ps->n = 50;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
    }
    for(i=0; i < 5; i++)
    {
        printf("%d", ps->arr[i]);
    }
    int*ptr=realloc(ps->arr, 10*sizeof(int));
    assert(ptr != NULL);
    ps->arr = ptr;
    for(i=5;i<10;i++)
    {
        ps->arr[i] = i;
        printf("%d", ps->arr[i]);
    }
    free(ps->arr);
    ps->arr = NULL;
    free(ps);
    ps = NULL;
}
int main()
{
    //柔性数组-C99中，结构中的最后一个元素允许是未知大小的数组，这就叫做【柔性数组】成员
    /*
    柔性数组特点：
    1.结构中的柔性数组成员前面至少一个其他成员。
    2.sizeof返回的这种结构大小不包活柔性数组的内存。
    3.包含柔性数组成员的结构用malloc（）函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组预期的大小。
    */
    test1();//较好，方便内存释放，有利于访问速度
    test2();
    return 0;
}

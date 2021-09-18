#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct S
{
    int n;
    int arr[]; //��arr[0],δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
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
    //��������-C99�У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������顿��Ա
    /*
    ���������ص㣺
    1.�ṹ�е����������Աǰ������һ��������Ա��
    2.sizeof���ص����ֽṹ��С����������������ڴ档
    3.�������������Ա�Ľṹ��malloc�������������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ��������Ԥ�ڵĴ�С��
    */
    test1();//�Ϻã������ڴ��ͷţ������ڷ����ٶ�
    test2();
    return 0;
}

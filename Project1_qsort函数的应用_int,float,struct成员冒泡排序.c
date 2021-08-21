#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



int cmp_int(const void* e1, const void* e2)
{
    return  *(int*)e1 - *(int*)e2;
}

void test1()
{
    int arr[] = { 3,5,6,9,2,4,8 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    int j = 0;
    for (j = 0; j < sz; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

 




int cmp_float(const void* e1, const void* e2)
{
    return (int)(*(float*)e2 - *(float*)e1);
}

void test2()
{
    float f[] = { 9.0,8.0,4.0,6.0,5.0,3.0 };
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%f ", f[i]);
    }
    printf("\n");
}


typedef struct Stu         //类型声明
{
    char name[15];
    int age;
}Stu;                      //类型自定义


cmp_stu_by_name(const void* e1, const void* e2)
{
    return    strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}
cmp_stu_by_age(const void* e1, const void* e2)
{
    return    (((Stu*)e1)->age - ((Stu*)e2)->age);
}
void test3()
{
     Stu k[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",50} };
    int sz = sizeof(k) / sizeof(k[0]);
    qsort(k, sz, sizeof(k[0]), cmp_stu_by_name);
    int m = 0;
    for (m = 0; m < sz; m++)
    {
        printf("name=%s age=%d      ", k[m].name,k[m].age);
    }
    printf("\n");

    qsort(k, sz, sizeof(k[0]), cmp_stu_by_age);
    int n = 0;
    for (n = 0; n < sz; n++)
    {
        printf("name=%s age=%d      ", k[n].name, k[n].age);
    }

}


int main()
{
    test1();//整型冒泡排序
    test2();//浮点型冒泡排序
    test3();//结构体冒泡排序   按首字母排序  按年龄大小排序
    system("pause");
    return 0;
}


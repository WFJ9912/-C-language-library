#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>

void test4()
{
    /*
    char *strtok(char *str,const char *sep);
    sep参数是个字符串，定义了用作分隔符的字符集合
    第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
    strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
    strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
    strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
    如果字符串中不存在更多的标记，则返回NULL指针。
    */
    char arr[] = "192.168.3.21";
    char *p = ".";
    //192\0168.3.21
    char buf[1024] = {0};
    strcpy(buf, arr);
    //切割buf中字符串
    char *ret = NULL;
    for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
    {
        printf("%s\n", ret);//192 \n 168 \n 3 \n 21
    }
}
void test3()
{
    /*
    char *strtok(char *str,const char *sep);
    sep参数是个字符串，定义了用作分隔符的字符集合
    第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
    strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
    strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
    strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
    如果字符串中不存在更多的标记，则返回NULL指针。
    */
    char arr[] = "zpw@bitedu.tech";
    char *p = "@.";
    //zpw\0bitedu.tech
    char buf[1024] = {0};
    strcpy(buf, arr);
    //切割buf中字符串

    char *ret = strtok(arr, p);
    printf("%s\n", ret); //zpw

    ret = strtok(NULL, p);
    printf("%s\n", ret); //bitedu

    ret = strtok(NULL, p);
    printf("%s\n", ret); //tech
}
char *my_strstr(const char *p3, const char *p4)
{
    assert(p3 != NULL);
    assert(p4 != NULL);
    char *s1 = NULL;
    char *s2 = NULL;
    char *cur = (char *)p3;
    if (*p4 == '\0')
    {
        return (char *)p3;
    }
    while (*cur)
    {
        s1 = cur;
        s2 = (char *)p4;
        while ((*s2) && (*s1) && (*s1 == *s2))
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
        {
            return cur; //找到字符串
        }
        if (*s1 == '\0')
        {
            return NULL; //提前结束
        }
        cur++;
    }
    return NULL; //找不到字符串
}
void test2()
{
    /*
    char *strstr (const char*,const char*);
    Returns a pointer to the ?rst occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
    */
    char *p1 = "abcdefc";
    char *p2 = "def";
    char *ret = strstr(p1, p2);
    if (ret == NULL)
    {
        printf("字符串不存在\n");
    }
    else
    {
        printf("%s\n", ret); //defc
    }

    char *p3 = "abcdefgo";
    char *p4 = "cd";
    char *ret1 = my_strstr(p3, p4);
    if (ret1 == NULL)
    {
        printf("字符串不存在\n");
    }
    else
    {
        printf("%s\n", ret1); //cdefgo
    }
}

void test1()
{
    /*
    char *strerror (int errnum);
    错误码 错误信息
    0      No error
    1      Operation not permitted
    2      No such file or directory
    ...
    errno是一个全局的错误码变量
    当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值到errno中
    */
    FILE *pf = fopen("test.txt", "r"); //打开文件函数 文件名 只读
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno)); //No such file or directory
    }
    else
    {
        printf("open file success\n");
    }
}

int main()
{
    test1(); //strerror函数的应用-字符串查错
    test2(); //strstr函数的应用-字符串查找
    test3(); //strtok函数的应用-字符串分割-低效
    test4(); //strtok函数的应用2-字符串分割-高效
    return 0;
}
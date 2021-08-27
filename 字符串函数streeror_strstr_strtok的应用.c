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
    sep�����Ǹ��ַ����������������ָ������ַ�����
    ��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
    strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�롣��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
    strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
    strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
    ����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ�롣
    */
    char arr[] = "192.168.3.21";
    char *p = ".";
    //192\0168.3.21
    char buf[1024] = {0};
    strcpy(buf, arr);
    //�и�buf���ַ���
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
    sep�����Ǹ��ַ����������������ָ������ַ�����
    ��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
    strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�롣��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
    strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
    strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
    ����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ�롣
    */
    char arr[] = "zpw@bitedu.tech";
    char *p = "@.";
    //zpw\0bitedu.tech
    char buf[1024] = {0};
    strcpy(buf, arr);
    //�и�buf���ַ���

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
            return cur; //�ҵ��ַ���
        }
        if (*s1 == '\0')
        {
            return NULL; //��ǰ����
        }
        cur++;
    }
    return NULL; //�Ҳ����ַ���
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
        printf("�ַ���������\n");
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
        printf("�ַ���������\n");
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
    ������ ������Ϣ
    0      No error
    1      Operation not permitted
    2      No such file or directory
    ...
    errno��һ��ȫ�ֵĴ��������
    ��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��errno��
    */
    FILE *pf = fopen("test.txt", "r"); //���ļ����� �ļ��� ֻ��
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
    test1(); //strerror������Ӧ��-�ַ������
    test2(); //strstr������Ӧ��-�ַ�������
    test3(); //strtok������Ӧ��-�ַ����ָ�-��Ч
    test4(); //strtok������Ӧ��2-�ַ����ָ�-��Ч
    return 0;
}
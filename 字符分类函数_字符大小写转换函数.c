#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

/*
�ַ����ຯ��
����������Ĳ����������������ͷ�����
    iscntrl     �κο����ַ�
    isspace     �հ��ַ����ո�䣬��ҳ^f������"n'���س�r���Ʊ��"t���ߴ�ֱ�Ʊ��"v 
    isdigit     ʮ��������0-9
    isxdigit    ʮ���������֣���������ʮ�������֣�Сд��ĸa-f����д��ĸA-F
    islower     Сд��ĸa-z
    issupper    ��д��ĸA~Z
    isalnum     ��ĸ�������֣�a~z,A~Z,0~9
    ispunct     �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
    isgraph     �κ�ͼ���ַ�
    isprint     �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
�ַ�ת������
    int tolower��int c)  ��дת��Сд��ĸ
    int toupper��int c)  Сдת����д��ĸ
    ��     char ch = tolower('Q');
           putchar(ch);//q
}
*/
int main()
{
    char ch = '2';
    int ret = isdigit(ch); //�ַ����ຯ��-ʮ��������
    printf("%d\n", ret);   //1 �������������棨һ����0����������

    char arr[] = "I Am A Student";
    int i = 0;
    while (arr[i])
    {
        if (isupper(arr[i]))
        {
            arr[i] = tolower(arr[i]);
        }
        i++;
    }
    printf("%s\n", arr);//i am a student
    return 0;
}
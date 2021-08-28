#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

/*
字符分类函数
函数如果他的参数符合下列条件就返回真
    iscntrl     任何控制字符
    isspace     空白字符：空格′，换页^f，换行"n'，回车r，制表符"t或者垂直制表符"v 
    isdigit     十进制数字0-9
    isxdigit    十六进制数字，包括所有十进制数字，小写字母a-f，大写字母A-F
    islower     小写字母a-z
    issupper    大写字母A~Z
    isalnum     字母或者数字，a~z,A~Z,0~9
    ispunct     标点符号，任何不属于数字或者字母的图形字符（可打印）
    isgraph     任何图形字符
    isprint     任何可打印字符，包括图形字符和空白字符
字符转换函数
    int tolower（int c)  大写转换小写字母
    int toupper（int c)  小写转换大写字母
    如     char ch = tolower('Q');
           putchar(ch);//q
}
*/
int main()
{
    char ch = '2';
    int ret = isdigit(ch); //字符分类函数-十进制数字
    printf("%d\n", ret);   //1 符合条件返回真（一个非0的正整数）

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
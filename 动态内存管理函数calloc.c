#define _CRT_SECURE_NO_WARNINGS 1            
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <string.h>

/*
动态内存函数之-calloc
void *malloc( size_t num,size_t size );
1.函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0.
2.与函数malloc的区别只在于calloc会在返回地址之前把申请的空间的每个字节初始化为全0.

*/
int main()
{
    int *p = (int*)calloc(10, sizeof(int));
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        int i = 0;
        for(i = 0; i < 10; i++)
        {
            printf("%d ",*(p+i));
        }
    }
    free(p);
    p = NULL;
    return 0 ;
}

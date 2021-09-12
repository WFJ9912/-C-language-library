#define _CRT_SECURE_NO_WARNINGS 1            
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <string.h>

/*
��̬�ڴ溯��֮-calloc
void *malloc( size_t num,size_t size );
1.�����Ĺ�����Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0.
2.�뺯��malloc������ֻ����calloc���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0.

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

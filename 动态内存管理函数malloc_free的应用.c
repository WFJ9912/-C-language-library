#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
��̬�ڴ溯��֮-malloc
void *malloc( size_t size );
����������ڴ�����һ���������õĿռ䣬������ָ�����ռ��ָ��
������ʧ�ܣ��򷵻�һ��NULLָ�룬���malloc�ķ���ֵһ��Ҫ�����
�������sizeΪ0��malloc����Ϊ��׼��δ����ģ�ȡ���ڱ�������

��̬�ڴ溯��֮-free
void free( void *memblock );
���������ר����������̬�ڴ���ͷźͻ��յ�
�������memblock��ָ��Ŀռ䲻�Ƕ�̬���ٵģ���free��������Ϊ��δ����ġ�
�������memblock��NULLָ�룬����ʲô�¶�����

*/
int main()
{
    //���ڴ�����10�����Ϳռ�
    int *p = (int*)malloc(10*sizeof(int));
    if(p == NULL)
    {
        //��ӡ����ԭ���һ����ʽ
        printf("%s\n",strerror(errno));
    }
    else
    {
        //����ʹ�ÿռ�
        int i = 0;
        for(i = 0; i < 10; i++)
        {
            *(p + i) = i;
        }
        for(i = 0; i < 10; i++)
        {
            printf("%d\t",*(p+i));//0 1 2 3 4 5 6 7 8 9 
        }
        //����̬����Ŀռ䲻��ʹ�õ�ʱ��
        //��Ӧ�û�������ϵͳ
        free(p);
        p = NULL;
    }
    return 0 ;
}
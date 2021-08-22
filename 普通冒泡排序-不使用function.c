#define _CRT_SECURE_NO_WARNINGS 1                
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int i=0;//趟数
	for(i=0;i<sz-1;i++)
	{
		int j=0;//对数
		for(j=0;j<sz-i-1;j++)
		{
			//比较方式
			if(arr[j] < arr[j+1])
			{
				int tmp=0;
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
		
	}
	int num=0;
		for(num=0;num<sz;num++)
		{
			printf("%d ",arr[num]);
		}
	return 0;
}
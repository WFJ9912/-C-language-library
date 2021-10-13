#define _CRT_SECURE_NO_WARNINGS 1          
#include<stdio.h>


/*
		1	2	3	4	m
	------------------
1	|	0	0	1	0
2	|	0 	0	0	0
3	|	0	0	1	0
4	|	0	1	0	0
5	|	0	0	0	1
n

问题：第一行有两个数n m。n表示迷宫的行，m表示迷宫的列。接下来的n行m列为迷宫，0表示空地，1表示障碍物。
最后一行4个数，前两个数为迷宫入口的x和y坐标。后两个为小哈的x和y坐标。
以最快速度解救小哈。

输出最短路径，即用的最少步数。

*/

int n,m,p,q,min=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
	//定义方向数组next
	/*
	1.1 1.2 1.3                   (x-1,y)
	2.1 2.2 2.3-------->(x,y-1)    (x,y)    (x,y+1)   
	3.1 3.2 3.3                   (x+1,y)
	*/
	int next[4][2] = {{0,1},//向右走
					{1,0},//向下走
					{0,-1},//向左走
					{-1,0}};//向上走
	//定义下一步的横坐标与纵坐标，及循环次数变量
	int tx,ty,k;
	//判断是否到达小哈的位置
	if(x==p && y==q)
	{
		//更新最小值
		if(step<min)
			min=step;
		return;//请注意这里的返回很重要
	}

	//枚举4种走法---通过方向数组，使用循环就很容易获得下一步的坐标。
	for(k=0;k<=3;k++)
	{
		//计算下一个点的坐标
		tx=x+next[k][0];
		ty=y+next[k][1];
		//判断是否越界
		if(tx<1||tx>n||ty<1||ty>m)
			continue;
		//判断该点是否为障碍物或者已经在路径中
		if(a[tx][ty]==0 && book[tx][ty]==0)
		{
			book[tx][ty]=1;//标记这个点已经走过
			dfs(tx,ty,step+1);//开始尝试下一个点
			book[tx][ty]=0;//尝试结束，取消这个点的标记
		}
	}
	return ;
}

int main()
{
	int i,j,sx,sy;
	//读入n和m，n为行，m为列
	scanf("%d %d",&n,&m);
	//读入迷宫
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	//读入起点和终点坐标
	scanf("%d %d %d %d",&sx,&sy,&p,&q);

	//从起点开始搜索
	book[sx][sy]=1;//标记起点已经在路径中，防止后面重复走
	//第一个参数是起点的x坐标，第二个参数是起点的y坐标，第三个参数是初始步数为0
	dfs(sx,sy,0);

	//输出最短步数
	printf("%d",min);
	getchar();getchar();
	return 0;
}

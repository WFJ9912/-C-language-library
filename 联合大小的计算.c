#include <stdio.h>

union Un
{
    int a;//4  默认对齐数8  4和8的最大公约数是4 因此对齐数为4
    char arr[5];//5 1(拿它的元素进行计算)  对齐数为1
};

int main()
{
    /*
    联合大小的计算
    1.联合的大小至少是最大成员的大小。
    2.当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
    */
    union Un u;
    printf("%d\n",sizeof(u));//8
    return 0;
}
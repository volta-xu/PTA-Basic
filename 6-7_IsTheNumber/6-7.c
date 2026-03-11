/*
6-7 统计某类完全平方数
本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。
int IsTheNumber ( const int N );    其中N是用户传入的参数。如果N满足条件，则该函数必须返回1，否则返回0。
*/

#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber(const int N)
{
    if (N < 0)
    {
        return 0;
    }
    int root = (int)sqrt(N);
    if (root * root != N)
    {
        return 0;
    }
    int count[10] = {0};
    int temp = N;
    if (temp == 0)
    {
        return 0;
    }
    while (temp > 0)
    {
        int digit = temp % 10;
        count[digit]++;
        if (count[digit] >= 2)
        {
            return 1;
        }
        temp /= 10;
    }
    return 0;
}
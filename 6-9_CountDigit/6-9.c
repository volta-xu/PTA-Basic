/*
6-9 统计个位数字
本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。
int Count_Digit ( const int N, const int D );   其中N和D都是用户传入的参数。N的值不超过int的范围；D是[0, 9]区间内的个位数。函数须返回N中D出现的次数。
*/

#include <stdio.h>

int Count_Digit(const int N, const int D);

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit(const int N, const int D)
{
    if (N == 0)
    {
        if (D == 0)
            return 1;
        else
            return 0;
    }
    int count = 0;
    int temp = N;
    while (temp != 0)
    {
        int digit = temp % 10;
        if (digit < 0)
        {
            digit = -digit;
        }
        if (digit == D)
        {
            count++;
        }
        temp /= 10;
    }
    return count;
}
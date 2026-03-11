/*
6-10 阶乘计算升级版
本题要求实现一个打印非负整数阶乘的函数。
void Print_Factorial ( const int N );   其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。
*/

#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial(const int N)
{
    if (N < 0)
    {
        printf("Invalid input\n");
        return;
    }
    if (N == 0 || N == 1)
    {
        printf("1\n");
        return;
    }
    int result[3000] = {0};
    result[0] = 1;
    int len = 1;
    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            int temp = result[j] * i + carry;
            result[j] = temp % 10;
            carry = temp / 10;
        }
        while (carry > 0)
        {
            result[len] = carry % 10;
            carry /= 10;
            len++;
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
    printf("\n");
}
/*
6-2 多项式求值
本题要求实现一个函数，计算阶数为n，系数为a[0] ... a[n]的多项式f(x)=a[0]*x^0 + a[1]*x^1 + ... + a[n]*x^n在x点的值。
double f( int n, double a[], double x );    其中n是多项式的阶数，a[]中存储系数，x是给定点。函数须返回多项式f(x)的值。
*/

#include <stdio.h>

#define MAXN 10

double f(int n, double a[], double x);

int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for (i = 0; i <= n; i++)
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

double f(int n, double a[], double x)
{
    double sum = 0.0;
    double p = 1.0;
    for (int i = 0; i <= n; i++)
    {
        sum += a[i] * p;
        p *= x;
    }
    return sum;
}
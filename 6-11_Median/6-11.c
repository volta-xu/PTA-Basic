/*
6-11 求自定类型元素序列的中位数
本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第⌊(N+1)/2⌋大的元素。其中集合元素的类型为自定义的ElementType。
ElementType Median( ElementType A[], int N );   其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。
*/

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

ElementType Median(ElementType A[], int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i++)
        {
            ElementType temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
            {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
    return A[N / 2];
}
/*
 有一分数序列： 2/1 3/2 5/3 8/5 13/8 21/13......
 求出这个数列的前N项之和，保留两位小数。
 */

#include <stdio.h>

int main(void)
{
    int n, a1, a2, a3, i;
    double sum = 0.0;

    scanf("%d", &n);
    if (n == 1)
        sum = 2.0;
    else if (n == 2)
        sum = 3.5;
    else
    {
        a1 = 1;
        a2 = 2;
        for (i = 0; i < n; i++)
        {
            a3 = a2 + a1;
            sum += (double)a2 / a1;
            a1 = a2;
            a2 = a3;
        }
    }
    printf("%.2lf", sum);
    return 0;
}
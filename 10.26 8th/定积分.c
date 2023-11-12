/*
求cosx，sinx，2x+1在[a,b]区间内的定积分，a、b的值从键盘输入。

①编写求定积分通用函数double integral(double a,double b,long n,
double (*p)(double))，形参a、b为积分区间，n为区间[a,b]等分数，p指向被积
函数。用梯形法计算p指向的函数在[a,b]的定积分近似值，返回计算结果。

②编写main函数，从键盘输入积分区间及等分数目，调用cos,sin,f函数求3个函
数定积分的近似值。


提示，函数调用形式为integral(a,b,n,cos)

f=2x+1
*/

#include <stdio.h>
#include <math.h>

double integral(double a, double b, long n, double (*p)(double));
double f3(double x)
{
    return 2 * x + 1;
}

int main(void)
{
    double a, b;
    long n;
    double (*p1)(double x), (*p2)(double x), (*p3)(double x);

    p1 = cos;
    p2 = sin;
    p3 = f3;
    scanf("a=%lf,b=%lf,n=%ld", &a, &b, &n);
    printf("integral cos:%lf\n", integral(a, b, n, p1));
    printf("integral sin:%lf\n", integral(a, b, n, p2));
    printf("integral 2x+1:%lf\n", integral(a, b, n, p3));
    return 0;
}

double integral(double a, double b, long n, double (*p)(double))
{
    int i;
    double sum = 0, length;
    length = (b - a) / n;
    for (i = 0; i < n; i++)
    {
        sum += (p(a + i * length) + p(a + (i + 1) * length)) * length / 2;
    }
    return sum;
}
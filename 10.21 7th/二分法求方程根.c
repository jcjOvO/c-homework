/*
**使用二分法求方程ex+x=0在(-1,1)之间的根。
**注意调用数学库函数前程序中要包含头文件math.h，
**不然可能出现异常的结果。
*/

#include <stdio.h>
#include <math.h>

double f(double x)
{
    double y;
    y = exp(x) + x;
    return y;
}
int main()
{
    double x1 = -1.0, x2 = 1.0, x;
    do
    {
        x = (x1 + x2) / 2;
        if (f(x1) * f(x) <= 0)
            x2 = x;
        if (f(x2) * f(x) <= 0)
            x1 = x;
    } while (fabs(x1 - x2) > 1e-6);
    printf("x=%lf", x);
    return 0;
}
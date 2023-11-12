/*
**已知f(x)=cos(x)-x，使用牛顿迭代法求解方程f(x)=0的近似解，
**要求精确到10-6。
**提示：自行估算迭代起始的x值，并且使用求出的x值代入f(x)进行验证结果是否正确。
**f’(x)=-sin(x)-1             x0=1
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double x, f1 = 1.0, f2 = 0.0;

    while (fabs(f1 - f2) > 1e-6)
    {
        f2 = f1;
        f1 = f1 - (cos(f1) - f1) / (-sin(f1) - 1);
    }
    f2 = fabs(cos(f1) - f1);
    printf("x=%lf\nf(x)=%lf", f1, f2);
    return 0;
}
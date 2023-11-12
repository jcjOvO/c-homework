/*采用递推法计算sinx幂级数展开式的近似值，当通项绝对值小于10-8时停止累加。*/

#include <stdio.h>

int main()
{
    double x, sinx, f;
    int n = 2;

    scanf("%lf", &x);
    f = x;
    sinx = x;
    while (f > 1e-8 || f < -1e-8)
    {
        f *= -1 * x * x / (n * (n + 1));
        sinx += f;
        n += 2;
    }
    printf("%.1lf", sinx);
    return 0;
}
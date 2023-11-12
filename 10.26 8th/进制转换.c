/*将十进制整数转换为任意n进制整数（n<=16）并输出。（用递归函数实现）*/
#include <stdio.h>

void f(int n, int base);

int main(void)
{
    int n, base;
    scanf("%d%d", &n, &base);
    f(n, base);
    return 0;
}

void f(int n, int base)
{
    int m;
    m = n % base;
    if (n >= base)
        f(n / base, base);
    if (m >= 10)
        printf("%c", m + 55);
    else
        printf("%c", m + '0');
}
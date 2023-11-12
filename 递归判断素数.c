/*用递归函数判断一个自然数是否为素数。*/
/*迷惑行为*/
#include <stdio.h>

int isprime(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", isprime(n));
    return 0;
}

int isprime(int n)
{
    int c = 1, i;

    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
            c = 0;
    }
    return c;
}
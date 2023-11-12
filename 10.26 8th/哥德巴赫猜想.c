/*哥德巴赫猜想：任何一个大于4的偶数都可以表示为两个素数之和。
验证[6,50]之间的偶数。

①   写函数void guest(int n)，找到并输出所有素数对，每个素数对之和均
等于偶数n。

②   编写main函数，遍历[6,50]间所有的偶数，调用guest函数查找并输出素数
对。*/
#include <stdio.h>
#include <math.h>

int isprime(int n);
void guest(int n);

int main(void)
{
    int i;

    for (i = 6; i <= 50; i += 2)
    {
        guest(i);
        putchar('\n');
    }
    return 0;
}

int isprime(int n)

{
    int c = 1, i;

    if (n == 0 || n == 1)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            c = 0;
            break;
        }
    }
    return c;
}

void guest(int n)
{
    int i;

    for (i = 3; i <= n / 2; i += 2)
    {
        if (isprime(i) && isprime(n - i))
            printf("%d=%d+%d ", n, i, n - i);
    }
}
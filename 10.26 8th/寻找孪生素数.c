/*寻找[m,n]区间内所有的孪生素数并输出。孪生素数是指差为2的两个素数，
例如，3和5，5和7。

①   编写函数int prime(int n)，判断素数。

②   编写main函数，接收键盘输入的m和n的值，寻找[m,n]区间内所有的孪生素数
并输出，并将孪生素数的对数输出，若区间内没有孪生素数，则输出“该区间内无
孪生素数”。*/
#include <stdio.h>
#include <math.h>
int isprime(int n);

int main(void)
{
    int count = 0, m, n;

    scanf("%d%d", &m, &n);
    while (m <= n - 2)
    {
        if (isprime(m) && isprime(m + 2))
        {
            printf("(%d,%d)\n", m, m + 2);
            count++;
        }
        m++;
    }
    if (count > 0)
        printf("t=%d\n", count);
    else
        printf("该区间内无孪生素数\n");
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
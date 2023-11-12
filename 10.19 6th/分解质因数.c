#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, m;
    scanf("%d", &n);
    printf("%d=", n);
    m = n;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (i == n)
        {
            printf("%d", n);
            return 0;
        }
        if (n % i == 0)
        {
            printf("%d*", i);
            n /= i;
            i--;
        }
    }
}

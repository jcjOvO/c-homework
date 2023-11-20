/*
对一个4×4的二维数组左下三角的全部元素（包含对角线上的元素）作如下变换：

⑴若该数是素数则用它的后继素数替换；（1不看做素数）

⑵若该数不是素数，则用0替换该数。

将变换后的数组及其数组左下三角的元素中的素数个数打印出来。
*/

#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int isprime(int n);
int nextprime(int n);
void print_array(int *p);
int main(void)
{
    int a[4][4], *p = &a[0][0], i, j, m, count = 0;
    for (i = 0; i < 16; i++)
    {
        scanf("%d", p);
        p += 1;
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (isprime(a[i][j]))
            {
                count++;
                a[i][j] = nextprime(a[i][j]);
            }
            else
                a[i][j] = 0;
        }
    }
    print_array(&a[0][0]);
    printf("count=%d", count);
    return 0;
}

int isprime(int n)
{
    int i;
    if (n == 1 || n == 0)
        return false;
    for (i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}
int nextprime(int n)
{
    do
    {
        n++;
    } while (fabs(isprime(n) - 1));
    return n;
}
void print_array(int *p)
{
    int i;
    for (i = 1; i <= 16; i++)
    {
        printf("%d", *(p + i - 1));
        if (i % 4 != 0)
            putchar(' ');
        else
            putchar('\n');
    }
}
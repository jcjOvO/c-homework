/*
 输出所有满足以下条件的3位整数：该数是素数，
 该数的个位数字与十位数字之和被10除所得余数恰好是该数的百位数字。
 例如，293是素数并且（3+9）被10除的余数是2，因此293是满足条
 件的3位素数。
 */

#include <stdio.h>
#include <math.h>
int main(void)
{
    int i, j, a, b, c, judge;

    for (i = 100; i < 1000; i++)
    {
        judge = 1;
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                judge = 0;
            }
        }
        if (judge)
        {
            a = i / 100;
            b = i / 10 % 10;
            c = i % 10;
            if ((b + c) % 10 == a)
            {
                printf("%d\n", i);
            }
        }
    }
}
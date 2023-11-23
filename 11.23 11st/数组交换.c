/*将数组中出现的素数首尾交换，
即第一个素数与最后一个素数交换，第二个素数与
倒数第二个素数交换......，非素数保持位置不变
，输出交换以后的数组*/
#include <stdio.h>
#include <math.h>

int isprime(int n);
void swap(int *a, int *b);
int main(void)
{
    int a[10], i = 0, j = 9, tmp;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    i = 0;
    do
    {
        if (isprime(a[i]) && isprime(a[j]))
            swap(a + i, a + j);
        do
        {
            i++;
        } while (!(isprime(a[i])));
        do
        {
            j--;
        } while (!(isprime(a[j])));
    } while (i < j);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

int isprime(int n)
{
    int i;
    for (i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*
寻找300以内（大于0）的所有的对称回文数并输出。回文数是指某数与其反序数相等
，如5、131、1551、345676543.

对称回文数指某数与其平方都是回文数。例如，n=11时，112=121；n=111时，
1112=12321。

①   编写函数int palindrome(long n)，判断n是否回文数，如是返回1，
否则返回0。

②   在main函数中遍历300以内的数，寻找对称回文数并输出。
*/
#include <stdio.h>

int palindrome(long n);

int main(void)
{
    long i;
    for (i = 1; i < 300; i++)
    {
        if (palindrome(i) && palindrome(i * i))
            printf("%d\n", i);
    }
    return 0;
}

int palindrome(long n)
{
    long m = 0, ori = n;

    do
    {
        m *= 10;
        m += n % 10;
    } while ((n /= 10) != 0);
    if (m != ori)
        return 0;
    else
        return 1;
}
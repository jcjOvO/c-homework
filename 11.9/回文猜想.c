/*验证猜想：任何一个十进制正整数与其反序数相加后得到一个新的正整数，对该正整
数重复上述处理最终可得到一个回文数。键盘输入的一个正整数，输出得到的回文数及
变换次数，若变换次数超过10000则停止变换，输出错误信息,若其本身是回文数则不
进行变换。

①编写函数int fun(long n, long *hw)，n是从主调函数接收的一个正整数，将最后
得到的回文数保存到hw指向的变量中，函数返回变换的次数。若变换次数超过10000则
停止变换，函数返回-1.

②编写main函数，声明局部变量a、b、c，接收键盘输入的一个正整数保存到a中，用a
作实参调用fun函数做变换，将得到的回文数保存到b中，变换次数保存到c中，输出得
到的回文数及变换次数。*/

#include <stdio.h>

int fun(long n, long *hw);
long reverse(long n);

int main(void)
{
    long a, b, c;
    long *p = &b;

    scanf("%d", &a);
    c = fun(a, p);
    if (c == -1)
        printf("error");
    else
        printf("%ld,%d", b, c);
    return 0;
}

int fun(long n, long *hw)
{
    int c = 0;
    long m = reverse(n);
    while (n != (m = reverse(n)) && c <= 10000)
    {
        n += m;
        c++;
    }
    *hw = m;
    return c <= 10000 ? c : -1;
}

long reverse(long n)
{
    long m = 0;
    do
    {
        m *= 10;
        m += n % 10;
    } while ((n /= 10) != 0);
    return m;
}
/*验证命题：任何各位数字不全相同的3位正整数经以下变换后均能变为495，
称495为3位整数的黑洞数。

变换步骤：对于任意一个各位数字不全相同的3位正整数，将组成该正整数的3
个数字重新组合分别生成一个最大数和一个最小数，用最大数减去最小数得到一个新
的3位数；再对新的3位数重复上述操作，最多重复7次。

编写程序，接收键盘输入的一个3位正整数，判断各位数字是否不全相同，若不全
相同则实施以上变换（不超过7次），输出每步变换后得到的3位整数。*/

#include <stdio.h>

int swap(int *a, int *b)
{
    int c;
    c = *a;
    *b = *a;
    *a = c;
}

int change(int a)
{
    int b, c, d, e, f;
    b = a / 100;
    c = a / 10 % 10;
    d = a % 10;

    if (b < c)
    {
        swap(&b, &c);
    }
    if (c < d)
    {
        swap(&d, &c);
    }
    if (b < c)
    {
        swap(&b, &c);
    }
    e = b * 100 + d - d * 100 - b;
    return e;
}

int main(void)
{
    int n, n1, n2, n3;
    scanf("%d", &n);
    n1 = n / 100;
    n2 = n / 10 % 10;
    n3 = n % 10;
    if (n1 == n2 && n2 == n3 && n1 == n3)
    {
        return 0;
    }
    printf("%d", n);
    while (n != 495)
    {
        n = change(n);
        printf("-%d", n);
    }
    return 0;
}
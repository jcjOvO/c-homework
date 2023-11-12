/*学校里的“吃货协会”准备搞一个聚会，已经知道现有会员N人，把会员从1到N编号，
其中会长的号码是N号，凡是和会长是老朋友的，那么该会员的号码肯定和N有大于1的
公约数，否则都是新朋友，现在会长想知道究竟有几个新朋友？请你编程序帮会长计
算出来（N用键盘输入）。

①编写函数int gcd(int a,int b)，求a和b的最大公约数。

②编写main函数，接收键盘输入的N的值，寻找[1,N-1]区间内的与N的最大公约数为1
的数字，输出个数。*/
#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int n, count = 0, i;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
        if (gcd(n, i) == 1)
            count++;
    printf("%d\n", count);
    return 0;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
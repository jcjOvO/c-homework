/*输入若干个整数,以-1标记输入结束。输出其中的最大数*/

#include <stdio.h>

int main()
{
    int max, a;

    scanf("%d", &a);
    max = a;
    while (a != -1)
    {
        max = max > a ? max : a;
        scanf("%d", &a);
    }

    printf("%d", max);
    return 0;
}
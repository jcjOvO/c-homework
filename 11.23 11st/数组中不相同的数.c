/*统计一个数组中有多少不相同的数*/

#include <stdio.h>
int main(void)
{
    int a[10], i, j, count = 10;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < 10; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                count--;
                break;
            }
        }
    }
    printf("%d", count);
    return 0;
}
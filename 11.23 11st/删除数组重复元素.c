/*输入数组，删除重复出现的数据*/

#include <stdio.h>
int main(void)
{
    int a[10], i, j;
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
                a[i] = -1;
                break;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (a[i] != -1)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
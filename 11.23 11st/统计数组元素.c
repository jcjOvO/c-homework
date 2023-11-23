/*
题目描述
键盘输入数组，统计不同数据出现的次数
*/
#include <stdio.h>

int main(void)
{
    int a[10], i, j, tmp, count = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    tmp = a[0];
    printf("%d:", tmp);
    for (i = 0; i < 10; i++)
    {

        if (a[i] != tmp)
        {
            printf("%d\n", count);
            tmp = a[i];
            printf("%d:", tmp);
            count = 1;
        }
        else
            count++;
    }
    printf("%d", count);
    return 0;
}
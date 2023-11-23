#include <stdio.h>

void three_pig(int n, int x);
void check(int x, int n, int i, int j, int chess[][10], int a[]);
int main(void)
{
    int t, x, i, n;
    scanf("%d%d", &t, &x);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        three_pig(n, x);
    }
}

void three_pig(int n, int x)
{
    int a[5] = {0}, chess[10][10] = {0}, i, j, count = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &chess[i][j]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            check(x, n, i, j, chess, a);
        }
    }
    if (a[1])
    {
        count++;
    }
    if (a[2])
    {
        count++;
    }
    if (a[4])
    {
        count++;
    }
    if (count != 1)
    {
        printf("draw\n");
        return;
    }
    if (a[1])
    {
        printf("1\n");
    }
    if (a[2])
    {
        printf("2\n");
    }
    if (a[4])
    {
        printf("4\n");
    }
}

void check(int x, int n, int i, int j, int chess[][10], int a[])
{
    if (chess[i][j] == 0)
        return;
    int N = 1, S = 1, W = 1, E = 1, k, flag;
    if (j < x - 1)
        W = 0;
    if (i < x - 1)
        N = 0;
    if (j + x > n)
        E = 0;
    if (i + x > n)
        S = 0;
    if (N)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i - k][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (S)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i + k][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (W)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i][j - k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (E)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i][j + k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (N && E)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i - k][j + k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (S && E)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i + k][j + k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (S && W)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i + k][j - k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
    if (N && W)
    {
        flag = 1;
        for (k = 1; k < x; k++)
        {
            if (chess[i][j] != chess[i - k][j - k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            a[chess[i][j]]++;
            return;
        }
    }
}
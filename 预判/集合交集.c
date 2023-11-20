/*
二维数组每行保存着一个整数集合，共有5个集合，
每个集合均包含5个元素。编写程序求出这五个集合的交集。所谓交集是指由所有同时出现在这5个集合中的元素组成的集合。
*/
#include <stdio.h>

int ifexist(int (*p)[5], int n);
void sort(int *n);
void swap(int *a, int *b);

int main(void)
{
    int a[5][5], *p1 = &a[0][0], *p2 = p1, i;

    while (p1 <= &a[4][4])
    {
        scanf("%d", p1);
        p1++;
    }
    sort(p2);
    for (i = 0; i < 5; i++)
    {
        if (ifexist(a, a[0][i]))
            printf("%d ", a[0][i]);
    }
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void sort(int *n)

{
    int i, j, temp, len = 5;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        {
            if (*(n + j) > *(n + j + 1))
                swap((n + j), (n + j + 1));
        }
}
int ifexist(int (*p)[5], int n)
{
    int i, j;
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (n == p[i][j])
                break;
            if (j == 4)
                return 0;
        }
    }
    return 1;
}
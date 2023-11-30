/*
按要求编写程序。

⑴ 编写函数void  line_sort(int a[ ][4],int b[ ],int n)，
n为行数，根据a指向的数组，计算各行元素之和，并保存到b指向的数组中，
根据和的大小将a指向的数组以行为单位按从小到大的顺序重新排列。

⑵ 编写main函数，初始化二维数组，输出原始数组，并调用line_sort函数得到变化以后的数组及每行之和
，输出新数组的各行元素以及每行元素的和
*/
#include <stdio.h>
void line_sort(int a[][4], int b[]);
void print_array(int a[][4]);
void swap(int *a, int *b);
void swap_line(int a[], int b[]);

int main(void)
{
    int a[5][4], b[5] = {0}, *p = &a[0][0], i;
    while (p <= &a[4][3])
    {
        scanf("%d", p);
        p++;
    }
    line_sort(a, b);
    print_array(a);
    printf("sum\n");
    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);
    return 0;
}

void print_array(int a[][4])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}
void swap_line(int a[], int b[])
{
    int i;
    for (i = 0; i < 4; i++)
        swap(&a[i], &b[i]);
}

void line_sort(int a[][4], int b[])
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 4; j++)
            b[i] += a[i][j];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                swap_line(a[j], a[j + 1]);
            }
        }
    }
}
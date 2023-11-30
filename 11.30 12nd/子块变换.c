/*完成对n阶矩阵(n为奇数)的变换，将原矩阵左下角n/2阶子块中的数据
与右上角 n/2 阶子块中的数据作交换，显示交换过子块后的n阶矩阵。*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, **matrix, i, j, tmp;
    scanf("%d", &n);
    matrix = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }

    for (i = 0; i < n / 2; i++)
    {
        for (j = n / 2 + 1; j < n; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i + n / 2 + 1][j - n / 2 - 1];
            matrix[i + n / 2 + 1][j - n / 2 - 1] = tmp;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
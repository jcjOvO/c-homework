/*将两个按字典顺序排序的名字登记表合并，删除重复出现的名字使得每个名字在登记表中只出现一次，输出名字登记表内容。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(void)
{
    char *s1[MAX] = {0}, *s2[MAX] = {0}, *tar[MAX * 2] = {0}, tmp[MAX];
    int i, n1, n2, j = 0, m, k = 0;
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%s", tmp);
        s1[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(s1[i], tmp);
    }
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%s", tmp);
        s2[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(s2[i], tmp);
    }
    i = 0;
    tar[0] = s1[0];
    while (i < n1 && j < n2)
    {
        if (m = strcmp(s1[i], s2[j]))
        {
            if (m > 0)
            {
                if (k == 0 || strcmp(tar[k - 1], s2[j]))
                    tar[k++] = s2[j++];
                else
                    j++;
            }
            else
            {
                if (k == 0 || strcmp(tar[k - 1], s1[i]))
                    tar[k++] = s1[i++];
                else
                    i++;
            }
        }
        else
        {
            i++;
        }
    }
    if (i == n1)
    {
        while (j < n2)
        {
            if (strcmp(tar[k - 1], s2[j]))
                tar[k++] = s2[j++];
            else
                j++;
        }
    }
    else
    {
        while (i < n1)
        {
            if (strcmp(tar[k - 1], s1[i]))
                tar[k++] = s1[i++];
            else
                i++;
        }
    }

    for (i = 0; tar[i] != 0; i++)
        printf("%s ", tar[i]);

    for (i = 0; i < n1; i++)
        free(s1[i]);
    for (i = 0; i < n2; i++)
        free(s2[i]);
    return 0;
}
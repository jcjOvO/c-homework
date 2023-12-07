/*⑴ 编写函数void count(char a[], char w[][10], int n,int b[])。
其功能是统计w指向的数组中的n个单词在a指向的字符串中各自出现的次数(将非字母字符看做单词分隔符)，
并将统计结果依次保存在b指向的数组中。

⑵ 编写main()函数，从键盘输入字符串，将数据保存在数组中，调用count()函数做统计，
并在屏幕上打印统计结果（每个单词及其出现次数）。*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count(char a[], char w[][10], int n, int b[]);
int main(void)
{
    int n, b[2] = {0}, i = 0, flag = 0, j = 0;
    char a[100] = {0}, w[2][10] = {0};

    gets(a);
    while (flag < 2)
    {
        while (isalpha(a[i]))
        {
            w[flag][j] = a[i];
            i++;
            j++;
        }
        i++;
        j = 0;
        flag++;
    }

    count(a, w, 2, b);
    printf("%s:%d %s:%d", w[0], b[0], w[1], b[1]);
    return 0;
}
void count(char a[], char w[][10], int n, int b[])
{
    char currentWord[10] = {0};
    int i = 0, j;

    while (a[i] != '\0')
    {
        j = 0;
        while (isalpha(a[i]))
        {
            currentWord[j] = a[i];
            i++, j++;
        }
        i++;
        currentWord[j] = '\0';
        if (strcmp(w[0], currentWord) == 0)
            b[0]++;
        if (strcmp(w[1], currentWord) == 0)
            b[1]++;
    }
}
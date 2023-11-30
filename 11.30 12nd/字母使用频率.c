/*编写一个程序，统计输入一行字符串中各个字母使用频率（
大小写不区分），将次数不为零的字母及次数输出。*/
#include <stdio.h>

int main(void)
{
    char a[100];
    int count[123] = {0};
    int i = -1;
    gets(a);
    while (a[++i] != '\0')
    {
        count[a[i]]++;
    }
    for (i = 97; i < 124; i++)
    {
        if (count[i] != 0)
            printf("%c:%d ", i, count[i]);
    }
    return 0;
}
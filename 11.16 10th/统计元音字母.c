/*
统计元音字母出现的次数。（元音字母：a o e i u）

①   编写函数count，用来计算输入字符串序列的元音字母数字，
具体组织形式自行设计

②   编写main函数，输入字符序列，调用count函数处理，并将统计结
果保存到main函数的局部变量中，输出字符串及统计结果。*/
#include <stdio.h>
#define MAX_ABT 100
int count(char *a);

int main(void)
{
    char str[MAX_ABT];
    gets(str);
    printf("%s,%d", str, count(str));
    return 0;
}

int count(char *a)
{
    int n = 0;
    while (*a != '\0')
    {
        switch (*a)
        {
        case 'a':
            n++;
            break;
        case 'o':
            n++;
            break;
        case 'i':
            n++;
            break;
        case 'e':
            n++;
            break;
        case 'u':
            n++;
            break;
        }
        a++;
    }
    return n;
}

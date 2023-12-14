/*编写程序删除s数组中不符合C语言标识符命名规则的字符串，并输出剩余的字符串。*/
#include <stdio.h>
#include <ctype.h>
int check(char *s);
int main(void)
{
    char s[5][100];
    int i;

    for (i = 0; i < 5; i++)
    {
        scanf("%s", s[i]);
    }
    for (i = 0; i < 5; i++)
    {
        if (check(s[i]))
            printf("%s ", s[i]);
    }
    return 0;
}
int check(char *s)
{
    int i = 1;
    if (isalpha(s[0]) || s[0] == '_')
        ;
    else
        return 0;

    while (s[i] != '\0')
    {
        if (isalpha(s[i]) || isdigit(s[i]) || s[i] == '_')
            ;
        else
            return 0;
        i++;
    }
    return 1;
}
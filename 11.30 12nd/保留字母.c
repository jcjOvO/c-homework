/*编一个程序，输入一个字符串，将组成字符串的所有非英文字母的字符删除后输出。*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int i, j;
    char a[80] = {0};
    gets(a);

    for (i = 0; i < 80; i++)
    {
        if (a[i] == '\0')
            break;

        if (isalpha(a[i]))
            ;
        else
        {
            for (j = i; a[j] != '\0'; j++)
            {
                a[j] = a[j + 1];
            }
            i--;
        }
    }
    puts(a);
    return 0;
}
/*寻找字符串中最长的单词并输出(将非字母字符看做单词分隔符)。*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tar[101];
    int i = 0, tmp = 0, count = 0, len = 0;

    gets(tar);
    while (tar[i] != '\0')
    {
        if (isalpha(tar[i]))
        {
            count++;
        }
        else
        {
            if (count > len)
            {
                tmp = i - count;
                len = count;
            }
            count = 0;
        }
        i++;
    }
    while (isalpha(tar[tmp]))
    {
        putchar(tar[tmp]);
        tmp++;
    }
    return 0;
}
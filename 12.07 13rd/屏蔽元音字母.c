/*在所给的10个单词中找出不包含元音字母（a,e,i,o,u）的单词，
将符合条件的单词的个数以及这些单词按照字典顺序输出。

⑴ 编写函数int FindNoVowel(char *str[],int num,char res[][20])，str指向的指针数组中保存若干单词字符串的首地址，
num保存单词的个数，res指向的数组保存找到的符合条件的单词字符串，每行存放一个单词，要求将符合条件的单词按字典顺序存储，
函数返回符合条件的单词个数。

⑵ 编写main()函数，从键盘输入数组，调用函数FindNoVowel，将符合条件的所有单词按字典顺序输出，
单词之间用1个空格隔开。   */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[10][20], tmp[20];
    int i, j, flag;
    for (i = 0; i < 10; i++)
    {
        scanf("%s", word[i]);
    }
    for (i = 0; i < 9; i++)
    {
        flag = 1;
        for (j = 0; j < 9 - i; j++)
        {
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tmp);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; word[i][j] != '\0'; j++)
        {
            if (word[i][j] == 'a' || word[i][j] == 'o' || word[i][j] == 'i' || word[i][j] == 'e' || word[i][j] == 'u')
            {
                word[i][0] = '\0';
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (word[i][0] != '\0')
            printf("%s ", word[i]);
    }
    return 0;
}

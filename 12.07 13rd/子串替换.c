/*⑴ 编写函数int replace_str(char *s,char *t,char *g)，
利用字符串处理函数将母串s中出现的所有子串t替换成子串g，返回替换的次数。

⑵ 编写main函数，键盘输入母串s、子串t及子串g，调用replace_str函数替换，输出新串及替换次数。*/
#include <stdio.h>
#include <string.h>

int replace_str(char *s, char *t, char *g);

int main(void)
{
    char s[1000] = {0}, t[50], g[50];
    int times;
    scanf("%s", s);
    scanf("%s", t);
    scanf("%s", g);

    times = replace_str(s, t, g);

    printf("%s\ncount:%d", s, times);
    return 0;
}

int replace_str(char *s, char *t, char *g)
{
    int count = 0;
    int t_len = strlen(t);
    int g_len = strlen(g);
    int s_len = strlen(s);
    char *pos = strstr(s, t);
    while (pos != NULL)
    {
        memmove(pos + g_len, pos + t_len, s_len - (pos - s) - t_len + 1);
        memcpy(pos, g, g_len);
        count++;
        s_len = strlen(s);
        pos = strstr(pos + g_len, t);
    }

    return count;
}
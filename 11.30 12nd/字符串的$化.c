/*按以下要求编写程序。

⑴ 编写函数void fun(char xx[])，其功能是在xx所指向的字符串中的所有数字字符之前
分别插入1个字符'$'，除了xx指向的字符串以外不允许用其他数组。

⑵ 编写main函数。从键盘输入一个包含数字字符的字符串，调用fun()函数对该字符串作
变换处理，在屏幕上打印处理后的字符串。*/

#include <stdio.h>
#include <ctype.h>

void fun(char p[]);
void swap(char *a, char *b);
int main(void)
{
    char a[100] = {0};
    gets(a);
    fun(a);
    puts(a);
    return 0;
}

void fun(char p[])
{
    int i = 0, j;
    char tmp;
    while (p[i] != '\0')
    {
        if (isdigit(p[i]))
        {
            tmp = '$';
            for (j = i; j == 0 || p[j - 1] != '\0'; j++) // 史山的诞生
            {
                swap(&tmp, p + j);
            }
            i++;
        }
        i++;
    }
}

void swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
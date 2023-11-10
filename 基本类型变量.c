/*
**编写程序，判断并输出所使用的编译器每种基本类型变量所占的存储空间大小。
**提示：程序的输出包括：short,int,float,double,char 类型变量所占的存储空间大小。
*/

#include <stdio.h>

int main(void)
{
    short a;
    int b;
    float c;
    double d;
    char e;
    int A, B, C, D, E;

    A = sizeof(a);
    B = sizeof(b);
    C = sizeof(c);
    D = sizeof(d);
    E = sizeof(e);

    printf("%d,%d,%d,%d,%d", A, B, C, D, E);
    return 0;
}
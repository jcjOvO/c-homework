/*
运算规则如下：

(a+bi)+(c+di)=(a+c)+(b+d)i

(a+bi)-(c+di)=(a-c)+(b-d)i

(a+bi)*(c+di)=(ac-bd)+(bc+ad)i

①   编写函数void fun(char op,double a,double b,double c,double d)，
根据op存储的运算符完成复数(a+bi)与(c+di)的算数运算。op为+、-、*之一，
运算结果保存至全局变量中。

②   编写main函数，输入两个复数及运算符，调用fun函数完成三种运算并按
以下格式输出运算结果。*/
#include <stdio.h>

void fun(char op, double a, double b, double c, double d);

double e, f;
int main(void)
{
    double a, b, c, d;
    char op;
    scanf("(%lf+%lfi)%c(%lf+%lfi)", &a, &b, &op, &c, &d);
    fun(op, a, b, c, d);
    printf("(%lf+%lfi)%c(%lf+%lfi)=(%lf)+(%lf)i\n", a, b, op, c, d, e, f);
    return 0;
}

void fun(char op, double a, double b, double c, double d)
{
    switch (op)
    {
    case '+':
        e = a + c;
        f = b + d;
        break;
    case '-':
        e = a - c;
        f = b - d;
        break;
    case '*':
        e = a * c - b * d;
        f = b * c + a * d;
        break;
    }
}
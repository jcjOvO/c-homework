/*一个结构数组数据处理程序。要求如下：

⑴ 自定义结构类型用于存储以下联系人信息，用typedef将类型标识符定义为PS。

long id ： 学号
char name[10]： 姓名
char sex[2] ： 性别（m 代表男，f 代表女）
⑵ 编写函数int delete(PS *p1, int m, PS *p2, int n) 。 p1指向数组中保存m个联系人信息， p2指向数组中保存n个联系人信息。从p1数组中删除在p2数组中重复出现的联系人信息(id值相同)。返回值为执行删除操作后p1数组中保存的联系人信息的数量。

⑶ 编写函数int merge(PS *p1, int m, PS *p2, int n) 。p1指向数组中保存m个联系人信息， p2指向数组中保存n个联系人信息。将p2数组中n个联系人信息合并到p1数组中。已知p1和p2数组中存储的联系人信息按成员id升序排列，合并后p1数组中的联系人信息仍按id升序排列。返回值为合并后p1数组中联系人信息的数量。

⑷ 编写函数void sort(PS *p, int n)，对p指向的数组中的n个联系人信息排序。要求：按性别排序（f在前m在后，f的编码小于m的编码），性别相同的按学号排序。

⑸ 编写函数void display(PS *p, int n)， 将p指向的数组中存储的n个联系人信息输出到显示器（每行显示一个联系人信息，信息间以空格分隔,输出完毕后另起一行输出“----”表示输出的结束）。

⑹ 编写main函数，声明结构数组a、b并用测试数据初始化（a、b数组中数据按成员id值升序存储）；按照输入的指令进行操作。

有如下几条指令：

delete，收到此指令时调用delete函数。
merge，收到此指令时调用merge函数。
sort1，收到此指令时调用sort函数,按要求对p1进行排序。
display1，收到此指令时调用display函数，按要求输出p1的全部元素。
display2，收到此指令时调用display函数，按要求输出p2的全部元素。*/

#include <stdio.h>
#include <string.h>

typedef struct PS
{
    long id;
    char name[10];
    char sex[2];
} PS;

int delete1(PS *p1, int m, PS *p2, int n);
int merge(PS *p1, int m, PS *p2, int n);
void sort(PS *p, int n);
void sortbyid(PS *p, int n);
void display(PS *p, int n);

int main(void)
{
    int m, n, i, j, k, result;
    char *order[5] = {"delete", "merge", "sort1", "display1", "display2"}, recv[10];
    PS a[50], b[10];

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %s %s", &a[i].id, a[i].name, a[i].sex);
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %s", &b[i].id, b[i].name, b[i].sex);
    }
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        scanf("%s", recv);
        for (k = 0; k < 5; k++)
        {
            if (strcmp(order[k], recv) == 0)
            {
                result = k;
                break;
            }
        }
        switch (result)
        {
        case 0:
            m = delete1(a, m, b, n);
            break;
        case 1:
            m = merge(a, m, b, n);
            break;
        case 2:
            sort(a, m);
            break;
        case 3:
            display(a, m);
            break;
        case 4:
            display(b, n);
            break;
        }
    }
    return 0;
}

int delete1(PS *p1, int m, PS *p2, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (p1[i].id == p2[j].id)
        {
            for (k = i; k < m; k++)
            {
                p1[k] = p1[k + 1];
            }
            m--;
            i++;
        }
        else if (p1[i].id < p2[j].id)
            i++;
        else
            j++;
    }
    return m;
}

int merge(PS *p1, int m, PS *p2, int n)
{
    int count = 0, i, j = 0, flag;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            flag = 1;
            if (p1[j].id == p2[i].id)
                flag = 0;
        }
        if (flag)
        {
            p1[m + count] = p2[i];
            count++;
        }
    }
    sortbyid(p1, m + count);
    return m + count;
}

void sortbyid(PS *p, int n)
{
    int i, j, min;
    PS tmp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j].id < p[min].id)
                min = j;
        }
        if (min != i)
        {
            tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
    }
}

void sort(PS *p, int n)
{
    int i, j, flag, f = 0;
    PS tmp;

    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].sex, "f") == 0)
        {
            f++;
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        if (strcmp(p[i].sex, "m") == 0)
        {
            flag = 1;
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(p[i].sex, p[j].sex) != 0)
                {
                    tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                sortbyid(&p[f], n - f);
                return;
            }
        }
    }
    sortbyid(&p[f], n - f);
    return;
}

void display(PS *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%ld %s %s\n", p[i].id, p[i].name, p[i].sex);
    }
    printf("----\n");
}
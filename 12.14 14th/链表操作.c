/*编写一个单向链表数据处理程序。要求如下。

数据类型:
struct  data_array{
   long num;
   int score;
 };

typedef  struct student{
  long num;
  int score;
  struct student *next;
} NODE;

（1）编写函数NODE * create(int n),创建一个按学号升序排列的新链表，链表中一共有n个结点。
（在函数中输入数据，测试数据按照学号升序输入）

（2）编写函数void merge(NODE *head1, NODE *head2)，将链表head2合并到链表head1中，若学号相同则保留成绩高的结点。

（3）编写函数void del(NODE *head1, NODE *head2)，从head1链表中删除与head2链表中有相同学号的那些结点。

（4）编写函数void display (NODE *head),输出链表，格式：每行一个结点，包括学号，分数，输出完成后，另起一行输出"----"。

（5）编写main函数，读取测试数据，创建链表，然后按照指令进行操作。

有如下几条指令：

merge，收到此指令时调用merge函数。
del，收到此指令时调用del函数。
display1，收到此指令时调用display函数，按要求输出链表1的全部元素。
display2，收到此指令时调用display函数，按要求输出链表2的全部元素。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_array
{
    long num;
    int score;
};

typedef struct student
{
    long num;
    int score;
    struct student *next;
} NODE;

NODE *create(int n);
void merge(NODE *head1, NODE *head2);
void del(NODE *head1, NODE *head2);
void display(NODE *head);

int main(void)
{
    int m, n, result, i, j, k;
    NODE *head1, *head2;
    char *order[4] = {"merge", "del", "display1", "display2"}, recv[10];

    scanf("%d", &m);
    head1 = create(m);
    scanf("%d", &n);
    head2 = create(n);
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        scanf("%s", recv);
        for (k = 0; k < 4; k++)
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
            merge(head1, head2);
            break;
        case 1:
            del(head1, head2);
            break;
        case 2:
            display(head1);
            break;
        case 3:
            display(head2);
            break;
        }
    }
    return 0;
}

NODE *create(int n)
{
    NODE *head, *p1, *p2;
    int i;
    head = (NODE *)malloc(sizeof(NODE));
    scanf("%ld %d", &head->num, &head->score);
    p1 = head;
    p2 = head;
    for (i = 1; i < n; i++)
    {
        p1 = (NODE *)malloc(sizeof(NODE));
        scanf("%ld %d", &p1->num, &p1->score);
        p2->next = p1;
        p2 = p1;
    }
    p2->next = NULL;
    return head;
}

void merge(NODE *head1, NODE *head2)
{
    NODE *p1 = head1, *p2 = head2, *p3 = head1, *p4;
    if (p1->num > p2->num)
    {
        p4 = (NODE *)malloc(sizeof(NODE));
        *p4 = *p1;
        *p1 = *p2;
        p1->next = p4;
        p2 = p2->next;
    }
    p1 = p1->next;
    while (p1 != NULL)
    {
        if (p2 == NULL)
            return;
        if (p1->num == p2->num)
        {
            if (p2->score > p1->score)
            {
                p1->score = p2->score;
            }
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next;
            continue;
        }
        if (p3->num < p2->num && p2->num < p1->num)
        {
            p3->next = (NODE *)malloc(sizeof(NODE));
            *(p3->next) = *p2;
            p3->next->next = p1;
            p3 = p3->next;
            p2 = p2->next;
        }
        else if (p3->num < p2->num && p2->num > p1->num)
        {
            p3 = p1;
            p1 = p1->next;
        }
        else if ((p3->num > p2->num && p2->num < p1->num))
            p2 = p2->next;
    }
    p1 = p3;
    while (p2 != NULL)
    {
        p1->next = (NODE *)malloc(sizeof(NODE));
        p1 = p1->next;
        *p1 = *p2;
        p1->next = NULL;
        p2 = p2->next;
    }
}

void del(NODE *head1, NODE *head2)
{
    NODE *p1 = head1, *p2 = head2, *p3 = head1, *p4 = NULL;

    while (p3->num == p2->num)
    {
        p1 = p3->next->next;
        p4 = p3->next;
        *p3 = *p4;
        free(p4);
        p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->num == p2->num)
        {
            p1 = p1->next;
            free(p3->next);
            p3->next = p1;
        }
        else if (p1->num < p2->num)
        {
            p3 = p1;
            p1 = p1->next;
        }
        else
            p2 = p2->next;
    }
}

void display(NODE *head)
{
    NODE *p = head;

    while (p != NULL)
    {
        printf("%ld %d\n", p->num, p->score);
        p = p->next;
    }
    printf("----\n");
}
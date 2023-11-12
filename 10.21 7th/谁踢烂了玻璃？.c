/*有4个小孩踢球，不小心打破了玻璃，老师问是谁干的？ A说：不是我 B说：是C
C说：是D D说：C冤枉了他！ 已知三人说了真话，一人说假话，谁打烂了玻璃？*/

#include <stdio.h>

int main(void)
{
    char liar;
    int count;
    for (liar = 'A'; liar < 'E'; liar++)
    {
        count = 0;
        if (liar != 'A')
            count++;
        if (liar == 'C')
            count++;
        if (liar == 'D')
            count++;
        if (liar != 'D')
            count++;
        if (count == 3)
        {
            printf("%c打烂了玻璃", liar);
            return 0;
        }
    }
}
/*方程x1+x2+x3+x4=30有多少满足x1>=2,x2>=0,x3>=-5,x4>=8的整数解？*/
#include <stdio.h>

int main(void)
{
    int x1, x2, x3, x4, count = 0;
    for (x3 = -5; x3 <= 30; x3++)
    {
        for (x2 = 0; x2 <= 35; x2++)
        {
            for (x1 = 2; x1 <= 35; x1++)
            {
                for (x4 = 8; x4 <= 35; x4++)
                {
                    if (x1 + x2 + x3 + x4 == 30)
                        count++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
#include <stdio.h>

int main()
{
    int num, a, b;
    int i = 0;
    scanf("%d", &num);
    while (num--)
    {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", ++i, a + b);
    }
}
#include <stdio.h>

int main()
{
    int a;

    while (true)
    {
        scanf("%d", &a);
        if (a == 0)
            break;
        printf("%d\n", a);
    }
}
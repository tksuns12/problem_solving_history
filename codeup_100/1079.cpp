#include <stdio.h>

int main()
{
    char a;

reload:
    scanf("%c", &a);
    printf("%c", a);
    if (a != 'q')
    {
        goto reload;
    }
}
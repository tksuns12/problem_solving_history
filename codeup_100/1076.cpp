#include <stdio.h>

int main()
{
    char a;
    scanf("%c", &a);
    for (int i = 'a'; i <= a; i++)
    {
        printf("%c ", i);
    }
}
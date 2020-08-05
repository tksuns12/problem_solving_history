
#include <stdio.h>

void is_even(int n)
{
    if (n % 2 == 0)
    {
        printf("%d\n", n);
    }
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    is_even(a);
    is_even(b);
    is_even(c);
}

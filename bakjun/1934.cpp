#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    fflush(stdin);

    while (n--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b / gcd(a, b));
    }
}
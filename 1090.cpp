#include <stdio.h>

int main()
{
    int a, r, n;
    scanf("%d %d %d", &a, &r, &n);
    long long result = a;
    for (int i = 1; i < n; i++)
    {
        result *= r;
    }

    printf("%lld", result);
}
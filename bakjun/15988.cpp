#include <stdio.h>

long long d[1000001];
long long mod = 1000000009LL;

int main()
{
    int t;
    scanf("%d", &t);
    fflush(stdin);
    int n;
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= 1000000; i++)
    {
        if (d[i] == 0)
        {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        d[i] %= mod;
    }

    while (t--)
    {
        scanf("%d", &n);

        printf("%lld\n", d[n]);
    }
}
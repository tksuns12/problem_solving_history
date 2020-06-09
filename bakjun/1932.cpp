#include <stdio.h>
#include <algorithm>

using namespace std;

int t[501][501];
int d[501][501];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }

    d[1][1] = t[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
        }
    }

    long long max = -1;

    for (int j = 1; j <= n; j++)
    {
        if (max < d[n][j])
        {
            max = d[n][j];
        }
    }

    printf("%lld", max);
}
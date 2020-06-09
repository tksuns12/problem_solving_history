#include <stdio.h>
#include <algorithm>

using namespace std;

long s[100001][3];
long long d[100001][3];

int main()
{
    int t, n;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int j = 1; j <= 2; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &s[i][j]);
            }
        }

        d[0][0] = d[0][1] = d[0][2] = 0;

        for (int i = 1; i <= n; i++)
        {
            d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + s[i][1];
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + s[i][2];
        }

        printf("%lld\n", max({d[n][0], d[n][1], d[n][2]}));
    }
}
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int wine[10001];
    int d[10001][3];

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &wine[i]);
    }
    d[1][0] = 0;
    d[1][1] = wine[1];
    d[1][2] = wine[1];
    d[2][0] = wine[1];
    d[2][1] = wine[2];
    d[2][2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++)
    {
        d[i][0] = max({d[i-1][2], d[i-1][1], d[i-1][0]});
        d[i][1] = d[i-1][0] + wine[i];
        d[i][2] = d[i-1][1] + wine[i];
    }

    printf("%d", max({d[n][0], d[n][1], d[n][2]}));
}
#include <stdio.h>

long long d[1001][10];

int mod = 10007;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= 9; i++)
    {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                d[i][j] += d[i - 1][k];
            }
            d[i][j] %= mod;
        }
    }

    int result = 0;

    for (int i = 0; i <= 9; i++)
    {
        result += d[n][i];
    }

    printf("%d", result % mod);
}

// 1부터 시작하는 무언가를 만들려고 하면 배열 크기를 +1 해주어야 한다.
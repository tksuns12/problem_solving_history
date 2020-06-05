#include <stdio.h>
#include <algorithm>

int main()
{
    int mod = 9901;

    int d[100000][3];
    int n;
    scanf("%d", &n);

    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;

    for (int i = 2; i <= n; i++)
    {
        d[i][0] = d[i - 1][1] % mod + d[i - 1][2] % mod;
        d[i][1] = d[i - 1][0] % mod + d[i - 1][2] % mod;
        d[i][2] = d[i - 1][0] % mod + d[i - 1][1] % mod + d[i - 1][2] % mod;
        d[i][0] %= mod;
        d[i][1] %= mod;
        d[i][2] %= mod;
    }

    int result = (d[n][0] + d[n][1] + d[n][2]) % mod;

    printf("%d\n", result);
}

// ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 오타 하나 %를 &으로 써서 틀렸다 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 진짜 바보다
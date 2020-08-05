#include <iostream>

using namespace std;

long long mod = 1000000000;
long long d[201][201][201];

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        if (i <= n)
        {
            d[i][1][i] += 1;
        }
    }

    for (int kg = 2; kg <= k; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int si = 0; si <=n; si++)
            {
            }
        }
    }
}

// 아.. 씨바 거진 다 풀었는데 ㅜㅜ
#include <stdio.h>

long long d[31];
int main()
{
    int n;
    scanf("%d", &n);

    d[0] = 1;

    for (int i = 2; i <= n; i += 2)
    {
        d[i] = d[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            d[i] += d[i - j] * 2;
        }
    }

    printf("%lld", d[n]);
}

// 경우의 수를 똑바로 세자. 그리고 배열 초기화는 반드시 전역으로 하자.
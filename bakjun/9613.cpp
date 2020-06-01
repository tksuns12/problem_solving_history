// 정수 n개가 주어졌을 때 가능한 모든 쌍의 GCD의 합을 구하는 문제

#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    int t;
    scanf("%d", &t);
    int arr[100];
    long long int sum = 0;
    int m;

    while (t--)
    {
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                sum += gcd(arr[i], arr[j]);
            }
        }
        printf("%lld\n", sum);
        sum = 0;
    }
    return 0;
}
// 후우... 입력을 long long으로 받았으면 출력도 long long으로 맞춰줘야 한다....
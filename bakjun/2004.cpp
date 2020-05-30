#include <stdio.h>

int main()
{
    long long m, n;
    scanf("%d %d", &n, &m);
    long five = 0;
    long two = 0;

    for (long long i = 2; i <= n; i *= 2)
    {
        two += n / i;
    }
    for (long long i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }
    for (long long i = 2; i <= n - m; i *= 2)
    {
        two -= (n - m) / i;
    }
    for (long long i = 5; i <= n - m; i *= 5)
    {
        five -= (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2)
    {
        two -= m / i;
    }
    for (long long i = 5; i <= m; i *= 5)
    {
        five -= m / i;
    }

    printf("%d", two > five ? five : two);
}

// 말아뭈다. 정신 집중도 제대로 안 됐던 데다가 문제를 제대로 읽지도.. 또 요구 사항을 제대로 못 봐서 int로 감당이 안 되는 수를 int로 받으려 했다....
// 또한 소인수 분해에 관한 것 숙지해야 한다.
// 차후에 8진수나 16진수에서 0의 개수를 알아내는 문제도 나올 수 있을 것 같다.
// 8진수의 경우라면 2의 개수를 세어서 3으로 나눈 몫을 반환하면 될 것 같고 16진수라면 4로 나눈 몫을 반환하면 될 것 같다.
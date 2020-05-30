#include <stdio.h>

// 팩토리얼 맨 뒤에 붙는 0의 개수를 세는 문제
void solve(int n, int &twos, int &fives)
{
    while (n%5 == 0 || n%2 == 0)
    {
        if (n % 5 == 0)
        {
            fives++;
            n /= 5;
        }
        else if (n % 2 == 0)
        {
            twos++;
            n /= 2;
        }
    }
}
int countten(int n)
{
    bool nums[n + 1];
    int twos = 0;
    int fives = 0;
    for (int i = 1; i <= n; i++)
    {
        solve(i, twos, fives);
    }
    return twos == 0 || fives == 0 ? 0 : twos > fives ? fives : twos;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", countten(n));
}

// 여기서 깨달은 점. 문제를 자세히 살펴보고 조건을 잘 살피고 무엇보다 중요한 것은 여러가지 극단적인 케이스를 테스트해봐야 한다.
// 2랑 5랑 다 체크할 필요 없이 무조건 2가 5보다 훨씬 많기 때문에 5의 개수를 세고 5가 두 번 들어간 경우만 체크해서 더해주면 된다.
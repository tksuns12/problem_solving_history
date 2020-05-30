#include <stdio.h>

// M이상 N이하의 소수를 모두 출력하는 문제

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    static bool primeList[1000000];

    for (int i = 2; i <= n; i++)
    {
        if (!primeList[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primeList[j] = true;
            }
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (!primeList[i] && i != 1)
        {
            printf("%d", i);
            if (i != n)
            {
                printf("\n");
            }
        }
    }
}

// 개같은 문제였다.... 일단 숫자가 100만이 나오면 배열 선언 동적으로 해줘야 되고 여튼 그렇다...

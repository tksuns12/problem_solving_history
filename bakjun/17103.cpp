#include <stdio.h>

bool is_prime[1000000];
int prime[1000000];

int main()
{
    int p = 0;
    is_prime[0] = true;
    is_prime[1] = true;
    for (int i = 2; i < 1000000; i++)
    {
        if (!is_prime[i])
        {
            prime[p++] = i;
            for (int j = i * 2; j < 1000000; j += i)
            {
                is_prime[j] = true;
            }
        }
    }

    int t;
    scanf("%d", &t);
    fflush(stdin);

    while (t--)
    {
        int n;
        int count = 0;
        scanf("%d", &n);
        for (int i = 0;  prime[i] <= n/2 && i < 1000000; i++) {
            if (!is_prime[(n - prime[i])]) {
                count++;
            }
        }
        printf("%d\n", count);

    }

    return 0;
}
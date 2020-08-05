/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
*/

#include <stdio.h>
int coin[1000001];
int main()
{
    int n, k;
    int count = 0;
    int i = 0;
    scanf("%d %d", &n, &k);

    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%d", &coin[i]);
    }

    while (k > 0)
    {
        if (k - coin[i] >= 0)
        {
            count++;
            k -= coin[i];
        }
        else
        {
            ++i;
            if (k - coin[i] >= 0)
            {
                count++;
                k -= coin[i];
            }
            else
            {
                continue;
            }
        }
    }

    printf("%d", count);
}
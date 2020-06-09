#include <stdio.h>
#include <algorithm>

using namespace std;

int d[1001];

int main()
{
    int n;
    int a[1001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = 1;
        int max = -1;
        for (int j = 1; j <= i; j++)
        {
            if (a[j] > a[i] && max < d[j])
            {
                max = d[j];
                d[i] = d[j] + 1;
            }
        }
    }

    int max = -1;

    for (int i = 1; i <= n; i++)
    {
        if (max < d[i])
        {
            max = d[i];
        }
    }
    printf("%d", max);
}
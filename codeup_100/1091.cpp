#include <stdio.h>

long long series(int a, int n, int m, int d) {
    if (n == 1) {
        return a;
    } else {
        return series(a, n-1, m, d) * m + d;
    }
}

int main()
{
    int a,m,d,n;

    scanf("%d %d %d %d", &a, &m,&d,&n);

    long long result = series(a, n, m, d);

    printf("%lld", result);

}
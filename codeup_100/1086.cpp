#include <stdio.h>

int main()
{
    long long w, h, b;

    scanf("%lld %lld %lld", &w, &h, &b);

    printf("%.2lf MB", double(w * h * b) / 1024 / 1024 / 8);
}
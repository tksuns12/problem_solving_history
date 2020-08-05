#include <stdio.h>

int main()
{
    long long h,b,c,s;
    scanf("%lld %lld %lld %lld", &h, &b, &c, &s);

    long long mul = h*b*c*s;
    double result = mul / double(1024);
    result = result / 1024 / 8;

    printf("%.1lf MB", result);
}
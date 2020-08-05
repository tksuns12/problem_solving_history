#include <stdio.h>

int main()
{
    int max;
    long long sum = 0;
    int inc = 1;
    scanf("%d", &max);

    while (sum < max) {
        sum += inc++;
    }

    printf("%d", sum);
}
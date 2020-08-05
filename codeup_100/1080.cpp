#include <stdio.h>

int main()
{
    int max;
    scanf("%d", &max);

    int sum = 0;
    int inc = 1;
    while (sum < max) {
        sum += inc++;
    }
    printf("%d", inc-1);
}
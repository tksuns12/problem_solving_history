#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);
    int mem[10000] = {};
    int max;
    for (int i = 1; i<=count; i++)
    {
        int k;
        scanf("%d", &k);
        mem[i] = k;
        max = i;
    }

    for (int i = max; i >= 1; i--) {
        printf("%d ", mem[i]);
    }

}
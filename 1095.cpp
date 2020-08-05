#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);
    int min = 24;
    for (int i = 1; i<=count; i++)
    {
        int k;
        scanf("%d", &k);
        if (min > k) {
            min = k;
        }
    }

    printf("%d", min);

}
#include <stdio.h>

int main()
{
    int k, n;
    scanf("%d", &k);
reload:
    scanf("%d", &n);
    if (k-- != 0)
    {
        printf("%d\n", n);

        goto reload;
    }
}
#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    scanf("%d", &a);
    char p_or_m[6];
    char e_or_o[5];

    if (a > 0) {
        strcpy(p_or_m, "plus");
    } else {
        strcpy(p_or_m, "minus");
    }

    if (a % 2 ==0) {
        strcpy(e_or_o, "even");
    } else {
        strcpy(e_or_o, "odd");
    }

    printf("%s\n%s", p_or_m, e_or_o);
}
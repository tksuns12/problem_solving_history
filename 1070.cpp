#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);
    switch (m)
    {
    case 12:
    case 1:
    case 2:
        printf("winter");
        break;
    case 3:
    case 4:
    case 5:
        printf("spring");
        break;
    case 6:
    case 7:
    case 8:
        printf("summer");
        break;
    default:
        printf("fall");
        break;
    }
}
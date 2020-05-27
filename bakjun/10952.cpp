#include <stdio.h>

int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0)
            break;
        printf("%d\n", a + b);
    }
}

// #include <stdio.h>
// int main() {
// 	int x, y;
// 	while (scanf("%d%d", &x, &y) && (x || y)) printf("%d\n", x + y);
// }
// 그렇구나... c에서는 0이 곧 false니까 저렇게 해도 되겠다...
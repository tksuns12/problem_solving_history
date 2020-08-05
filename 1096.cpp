#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int board[20][20] = {};

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
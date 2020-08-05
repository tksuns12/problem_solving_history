#include <stdio.h>

int main()
{
    int h, w, n;
    int board[101][101] = {};

    scanf("%d %d", &h, &w);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, d, x, y;
        scanf("%d %d %d %d", &l, &d, &x, &y);
        if (d == 0)
        {
            for (int i = 0; i < l; i++)
            {
                if (board[y + i][x] == 0)
                {
                    board[y + i][x] = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < l; i++)
            {
                if (board[y][x + i] == 0)
                {
                    board[y][x + i] = 1;
                }
            }
        }
    }

    for (int x = 1; x <= h; x++)
    {
        for (int y = 1; y <= w; y++)
        {
            printf("%d ", board[y][x]);
        }
        printf("\n");
    }

    return 0;
}
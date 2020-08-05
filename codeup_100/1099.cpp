#include <stdio.h>

int maze[11][11];

int main()
{

    int x = 2;
    int y = 2;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    while (true)
    {
        if (maze[y][x] == 2)
        {
            maze[y][x] = 9;
            break;
        }
        if (maze[y][x + 1] == 0)
        {
            maze[y][x] = 9;
            x++;
        }
        else if (maze[y][x + 1] == 1)
        {
            if (maze[y + 1][x] == 0)
            {
                maze[y][x] = 9;
                y++;
            }
            else if (maze[y + 1][x] == 1)
            {
                maze[y][x] = 9;
                break;
            }
            else if (maze[y + 1][x] == 2)
            {
                maze[y][x] = 9;
                maze[y + 1][x] = 9;
                break;
            }
        }
        else if (maze[y][x + 1] == 2)
        {
            maze[y][x] = 9;
            maze[y][x + 1] = 9;
            break;
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}
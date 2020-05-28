#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int series[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &series[i]);
    }

    stack<int> con;
    int oken[n];

    for (int i = 0; i < n; i++)
    {
        if (con.empty())
        {
            con.push(i);
        }
        else
        {
            while (!con.empty() && series[con.top()] < series[i])
            {
                oken[con.top()] = series[i];
                con.pop();
            }
            con.push(i);
        }
    }

    while (!con.empty())
    {
        oken[con.top()] = -1;
        con.pop();
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", oken[i]);
        if (i + 1 != n)
        {
            printf("%c", ' ');
        }
    }
}
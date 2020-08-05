#include <iostream>

using namespace std;

int a[1001];
long long d[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    d[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            d[i] = a[i] + d[i - 1];
        }
        else
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[j] < a[i] && d[i] != 0)
                {
                    d[i] = a[i] + d[j];
                }
            }
            if (d[i] == 0)
            {
                d[i] = a[i];
            }
        }
    }

    int max = -1000;

    for (int i = 1; i <= n; i++)
    {
        if (max < d[i])
        {
            max = d[i];
        }
    }

    cout << max;
}

//함 가보자
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, temp;
    int in = 0;
    int max = 0;
    stack<int> numStack;
    cin >> n;
    cin.ignore();
    int series[n];
    std::string result[2 * n];

    for (int i = 0; i < sizeof(series) / sizeof(*series); i++)
    {
        cin >> series[i];
    }

    for (int i = 0; i < sizeof(series) / sizeof(*series); i++)
    {
        if (max < series[i])
        {
            for (int j = max + 1; j <= series[i]; j++)
            {
                numStack.push(j);
                result[in++] = "+";
            }
            max = series[i];
            numStack.pop();
            result[in++] = "-";
        }
        else
        {
            if (series[i] == numStack.top())
            {
                numStack.pop();
                result[in++] = "-";
            }
            else
            {
                cout << "NO";
                break;
            }
        }
    }
    if (in == 2 * n)
    {
        for (int i = 0; i < sizeof(result) / sizeof(*result); i++)
        {
            cout << result[i] << '\n';
        }
    }
}
// #include <cstdio>
// #include <unistd.h>
// #define sz (1 << 15)
// #define f(x)                              \
//     {                                     \
//         x = 0;                            \
//         while (1)                         \
//         {                                 \
//             if (c == e)                   \
//                 syscall(0, 0, c = s, sz); \
//             if (*c < '0')                 \
//                 break;                    \
//             x = x * 10 + *c++ - '0';      \
//         }                                 \
//         c++;                              \
//     }
// int main()
// {
//     char s[sz], *c, *e;
//     c = e = s + sz;
//     int a[100000], x, n, m = 0, p = 0, q = 0;
//     char r[400000];
//     f(n);
//     for (int i = 0; i < n; i++)
//     {
//         f(x);
//         while (p < x)
//             a[q++] = ++p, r[m++] = '+', r[m++] = '\n';
//         if (a[--q] != x)
//             return !puts("NO");
//         r[m++] = '-', r[m++] = '\n';
//     }
//     r[--m] = 0;
//     puts(r);
// }
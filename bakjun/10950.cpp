#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    cin >> num;
    int results[num];

    while (num--)
    {
        int a;
        int b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
}

// #include <stdio.h>
// main()
// {
//     int n, i, a, b;
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d %d", &a, &b);
//         printf("%d\n", a + b);
//     }
// }
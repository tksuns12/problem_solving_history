#include <stdlib.h>
#include <iostream>

using namespace std;

int younger[100000];
int diff[100000];

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, s;
    cin.tie(nullptr);
    cin >> n >> s;
    long long g = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> younger[i];
        diff[i] = (s - younger[i]) > 0 ? (s - younger[i]) : (younger[i] - s);
    }
    for (int i = 0; i < n; i++)
    {
        if (n != 1)
        {
            if (g == 0)
            {
                g = gcd(diff[i], diff[i + 1]);
            }
            else
            {
                g = gcd(g, diff[i]);
            }
        }
    }
    printf("%lld", g == 0 ? diff[0] : g);
}
// #include <bits/stdc++.h>
// using namespace std;

// int n ,subin;
// int answer;

// void solve() {
//     int brother;
//     for (int i = 0; i < n; ++i) {
//         cin >> brother;
//         if (i == 0) answer = abs(subin - brother);
//         else {
//             answer = gcd(answer, abs(subin - brother));
//         }
//     }
//     cout << answer;
// }

// void input() {
//     cin >> n >> subin;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     //freopen("input.txt", "r", stdin);
//     cin.tie(NULL);  cout.tie(NULL);

//     input();
//     solve();

//     return 0;
// }

// 위 코드에서는 입력을 다 받아서 하는 게 아니라 하나씩 받을 때마다 최대공약수를 계산했다.
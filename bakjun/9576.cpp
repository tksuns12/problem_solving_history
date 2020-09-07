#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, m;
        int answer = 0;
        vector<pair<int, int>> apps;
        cin >> n >> m;
        vector<bool> given(n + 1, false);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            apps.push_back(make_pair(a, b));
        }

        sort(apps.begin(), apps.end(), cmp);

        for (pair<int, int> app : apps)
        {
            for (int i = app.first; i <= app.second; i++)
            {
                if (!given[i])
                {
                    answer++;
                    given[i] = true;
                    break;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
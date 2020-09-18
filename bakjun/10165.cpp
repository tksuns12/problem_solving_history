/*국경을 따라 순환 도로를 건설한 국가가 있다. 이 순환 도로에는 N개의 위치에 버스 정류소가 있으며, 버스 정류소에는 0부터 N-1까지 번호가 시계방향 순서로 지정되어 있다. 현재 여러 개의 버스 노선들이 이 순환 도로에서 운행되고 있다. 각 버스 노선은 [a,b]로 표시된다. 이 노선의 버스는 버스 정류소 a부터 b까지를 시계방향으로, b부터 a까지는 반시계방향으로 운행한다. 순환 도로 상의 모든 정류소를 포함하는 버스 노선은 존재하지 않는다. 

국가 교통행정부에서 비용 절감을 위해서 버스 노선 중 일부를 취소하려고 한다. 취소되는 노선은 다른 노선에 포함되어 있는 노선이다. 예를 들어, N=10일 때, 5개의 버스 노선이 다음과 같이 있다고 하자. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(const pair<int, pair<long, long>> &a, const pair<int, pair<long, long>> &b)
{
    if (a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first < b.second.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, pair<long, long>>> routes;
    long n, m;
    long terminal = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;
        if (a > b)
        {
            terminal = max(terminal, b);
            b += n;
        }
        routes.push_back({i + 1, {a, b}});
    }

    sort(routes.begin(), routes.end(), cmp);

    deque<pair<int, pair<long, long>>> dq;

    for (vector<pair<int, pair<long, long>>>::iterator i = routes.begin(); i != routes.end(); i++)
    {
        if (dq.empty() || dq.back().second.second < (*i).second.second)
            dq.push_back(*i);
    }

    while (!dq.empty() && dq.front().second.second <= terminal)
        dq.pop_front();

    sort(dq.begin(), dq.end(), [&](const pair<int, pair<long, long>> &a, const pair<int, pair<long, long>> &b) {
        return a.first < b.first;
    });

    for (pair<int, pair<long, long>> a : dq)
    {
        cout << a.first << ' ';
    }

    return 0;
}

/*스위핑 알고리즘.... 직선 경로 상에 있는 직선들이 서로 포함하는지 안 하는지를 찾는 것이다... 이것은 */
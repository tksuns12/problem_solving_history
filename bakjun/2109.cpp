/*한 저명한 학자에게 n(0≤n≤10,000)개의 대학에서 강연 요청을 해 왔다. 각 대학에서는 d(1≤d≤10,000)일 안에 와서 강연을 해 주면 p(1≤p≤10,000)만큼의 강연료를 지불하겠다고 알려왔다. 각 대학에서 제시하는 d와 p값은 서로 다를 수도 있다. 이 학자는 이를 바탕으로, 가장 많은 돈을 벌 수 있도록 순회강연을 하려 한다. 강연의 특성상, 이 학자는 하루에 최대 한 곳에서만 강연을 할 수 있다.

예를 들어 네 대학에서 제시한 p값이 각각 50, 10, 20, 30이고, d값이 차례로 2, 1, 2, 1 이라고 하자. 이럴 때에는 첫째 날에 4번 대학에서 강연을 하고, 둘째 날에 1번 대학에서 강연을 하면 80만큼의 돈을 벌 수 있다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long answer = 0;
    vector<pair<int, int>> lectures;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lectures.push_back({a, b});
    }
    vector<bool> did(10000, false);

    sort(lectures.begin(), lectures.end(), cmp);

    for (pair<int, int> lecture : lectures)
    {
        for (int i = lecture.second; i > 0; i--)
        {
            if (!did[i])
            {
                did[i] = true;
                answer += lecture.first;
                break;
            } else continue;
        }
    }

    cout << answer;

    return 0;
}
/*세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<pair<int, int>> jewels;
    vector<int> bags;
    priority_queue<int> pq;
    long long answer = 0ll;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        jewels.push_back(make_pair(temp1, temp2));
    }

    for (int i = 0; i < k; ++i)
    {
        int temp;
        cin >> temp;
        bags.push_back(temp);
    }

    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end());

    vector<pair<int, int>>::iterator p = jewels.begin();

    for (int bag : bags)
    {
        while (p != jewels.end() && (*p).first <= bag)
        {
            pq.push((*(p++)).second);
        }
        if (!pq.empty())
        {
            answer += (long long)pq.top();
            pq.pop();
        }
    }

    cout << answer;
}

/*lower_bound와 upper_bound로 해도 시간 초과가 날 리는 없는데 어쨌든.. 우선순위 큐와 multiset이 있다는 것을 알앗따..*/
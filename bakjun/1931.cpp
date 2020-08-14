/*한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다.
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> time;
    vector<pair<long long int, long long int>> series;

    for (int i = 0; i < n; ++i)
    {
        long long int a, b;
        cin >> a >> b;
        time.push_back(make_pair(a, b));
    }

    sort(time.begin(), time.end(), cmp);

    for (pair<long long, long long> var : time)
    {
        if (series.size() == 0)
            series.push_back(var);
        else
        {
            if (series.back().second <= var.first)
            {
                series.push_back(var);
            }
        }
    }
    cout << series.size();

    return 0;
}

/*완전히 접근 자체가 틀렸다. 회의실 배정 문제 같은 경우 종료 시간을 기준으로 정렬하는 것이 알고리즘의 핵심이다.*/
/*수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 

김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 

참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)

수강신청 대충한 게 찔리면, 선생님을 도와드리자!*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<pair<long long, long long>> times;
    multiset<long long> empty;
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long temp1;
        long long temp2;
        cin >> temp1 >> temp2;
        times.push_back(make_pair(temp1, temp2));
    }

    sort(times.begin(), times.end(), cmp);

    for (vector<pair<long long, long long>>::iterator i = times.begin(); i != times.end(); i++)
    {
        if (empty.empty())
        {
            empty.insert((*i).first);
            answer++;
        }
        else
        {
            multiset<long long>::iterator point = empty.upper_bound((*i).second);
            multiset<long long>::iterator point2 = empty.find((*i).second);

            if (point2 != empty.end())
            {
                empty.erase(point2);
                empty.insert((*i).first);
            }
            else if (point != empty.end())
            {
                empty.erase(point);
                empty.insert((*i).first);
            }
            else
            {
                empty.insert((*i).first);
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}
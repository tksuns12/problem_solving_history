/*기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다. 그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면, 

키보드
헤어드라이기
핸드폰 충전기
디지털 카메라 충전기
키보드
헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다. */

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<int> plan;
    map<int, int> count;
    set<int> tab;
    int answer = 0;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        plan.push_back(temp);
        if (count.find(temp) == count.end())
        {
            count.insert(make_pair(temp, 1));
        }
        else
        {
            count[temp]++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (tab.size() < n)
        {
            tab.insert(plan[i]);
            count[plan[i]]--;
        }
        else
        {
            if (tab.find(plan[i]) != tab.end())
            {
                count[plan[i]]--;
                continue;
            }
            else
            {
                int target = -1;
                for (pair<int, int> a : count)
                {
                    if (a.second == 0 && tab.find(a.first) != tab.end() && target == -1)
                    {
                        target = a.first;
                    }
                }

                if (target == -1)
                {
                    set<int> seen;
                    for (int j = i+1; j < k && seen.size() != n; j++)
                    {
                        if (tab.find(plan[j]) != tab.end() && seen.find(plan[j]) == seen.end())
                        {
                            target = plan[j];
                            seen.insert(target);
                        }
                    }
                }

                tab.erase(tab.find(target));
                answer++;
                tab.insert(plan[i]);
                count[plan[i]]--;
            }
        }
    }

    cout << answer;
}

/*그리디하게 스케줄링하는 문제... 잘 기억해두자...*/
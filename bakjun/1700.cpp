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
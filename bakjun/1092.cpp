/*지민이는 항구에서 일한다. 그리고 화물을 배에 실어야 한다. 모든 화물은 박스에 안에 넣어져 있다. 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 모든 크레인은 동시에 움직인다.

각 크레인은 무게 제한이 있다. 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cranes;
    vector<int> boxes;
    int n, m, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cranes.push_back(temp);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        boxes.push_back(temp);
    }

    sort(cranes.begin(), cranes.end(), cmp);
    sort(boxes.begin(), boxes.end(), cmp);

    while (!boxes.empty())
    {
        bool avail = false;
        for (int crane : cranes)
        {
            for (vector<int>::iterator j = boxes.begin(); j != boxes.end(); j++)
            {
                if (crane >= *j)
                {
                    avail = true;
                    boxes.erase(j);
                    break;
                }
                else
                    continue;
            }
        }
        if (!avail)
            break;
        else
            answer++;
    }

    if (boxes.empty())
        cout << answer;
    else
        cout << -1;

    return 0;
}


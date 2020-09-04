/*웅찬이는 과제가 많다. 하루에 한 과제를 끝낼 수 있는데, 과제마다 마감일이 있으므로 모든 과제를 끝내지 못할 수도 있다. 과제마다 끝냈을 때 얻을 수 있는 점수가 있는데, 마감일이 지난 과제는 점수를 받을 수 없다.

웅찬이는 가장 점수를 많이 받을 수 있도록 과제를 수행하고 싶다. 웅찬이를 도와 얻을 수 있는 점수의 최댓값을 구하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>
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

    int n;
    int answer = 0;
    int day = 1;
    int max = -1;
    cin >> n;
    vector<pair<int, int>> homeworks;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (max < temp1)
            max = temp1;
        homeworks.push_back(make_pair(temp1, temp2));
    }
    vector<bool> done(max, false);

    sort(homeworks.begin(), homeworks.end(), cmp);

    for (pair<int, int> hw : homeworks)
    {
        if (!done[hw.first - 1])
        {
            done[hw.first - 1] = true;
            answer += hw.second;
        }
        else
        {
            int position = hw.first - 1;
            while (done[position] && position > 0)
            {
                position--;
            }
            if (!done[position])
            {
                done[position] = true;
                answer += hw.second;
            }
        }
    }

    cout << answer;

    return 0;
}
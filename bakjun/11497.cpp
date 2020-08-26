/*남규는 통나무를 세워 놓고 건너뛰기를 좋아한다. 그래서 N개의 통나무를 원형으로 세워 놓고 뛰어놀려고 한다. 남규는 원형으로 인접한 옆 통나무로 건너뛰는데, 이때 각 인접한 통나무의 높이 차가 최소가 되게 하려 한다.

통나무 건너뛰기의 난이도는 인접한 두 통나무 간의 높이의 차의 최댓값으로 결정된다. 높이가 {2, 4, 5, 7, 9}인 통나무들을 세우려 한다고 가정하자. 이를 [2, 9, 7, 4, 5]의 순서로 세웠다면, 가장 첫 통나무와 가장 마지막 통나무 역시 인접해 있다. 즉, 높이가 2인 것과 높이가 5인 것도 서로 인접해 있다. 배열 [2, 9, 7, 4, 5]의 난이도는 |2-9| = 7이다. 우리는 더 나은 배열 [2, 5, 9, 7, 4]를 만들 수 있으며 이 배열의 난이도는 |5-9| = 4이다. 이 배열보다 난이도가 낮은 배열은 만들 수 없으므로 이 배열이 남규가 찾는 답이 된다.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int abs(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> logs;
        vector<int> sorted;
        int max = -1;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            logs.push_back(temp);
        }

        vector<int>::iterator max_ele = max_element(logs.begin(), logs.end());
        int max_num = *max_ele;
        sorted.push_back(max_num);
        logs.erase(max_ele);
        sort(logs.begin(), logs.end(), cmp);
        for (int i = 0; i < n - 1; ++i)
        {
            if (i % 2 == 0)
            {
                sorted.push_back(logs[i]);
            }
            else
            {
                sorted.insert(sorted.begin(), logs[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int diff;
            if (i == n - 1)
            {
                diff = abs(sorted[i] - sorted[0]);
            }
            else
            {
                diff = abs(sorted[i + 1] - sorted[i]);
            }
            if (max < diff)
                max = diff;
        }

        cout << max << '\n';
    }
    return 0;
}
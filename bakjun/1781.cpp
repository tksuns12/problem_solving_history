/*상욱 조교는 동호에게 N개의 문제를 주고서, 각각의 문제를 풀었을 때 컵라면을 몇 개 줄 것인지 제시 하였다. 하지만 동호의 찌를듯한 자신감에 소심한 상욱 조교는 각각의 문제에 대해 데드라인을 정하였다.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(200001, 0);

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > a.first;
    return a.second > b.second;
}
int find(int a)
{
    if (parent[a] == a)
        return a;
    else
    {
        return parent[a] = find(parent[a]);
    }
}
void uni(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 200000; i++)
    {
        parent[i] = i;
    }

    int n;
    int answer = 0;
    vector<pair<int, int>> problems;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        problems.push_back({a, b});
    }
    sort(problems.begin(), problems.end(), cmp);

    for (pair<int, int> problem : problems)
    {
        if (find(problem.first) != 0)
        {
            answer += problem.second;
            uni(parent[problem.first] - 1, problem.first);
        }
    }

    cout << answer;

    return 0;
}

/*우와 바로 이전 문제에서 유니온-파인드 알고리즘을 배웠는데 이 문제에서 알차게 써먹었다. 엄청 유용하네.*/
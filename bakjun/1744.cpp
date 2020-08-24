/*길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.

수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.*/

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

    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    vector<int> zero;
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
            minus.push_back(temp);
        else if (temp > 1)
            plus.push_back(temp);
        else if (temp == 1)
            answer++;
        else
            zero.push_back(temp);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end(), cmp);

    while (plus.size() >= 2)
    {
        answer += plus.back() * *(plus.rbegin() + 1);
        plus.pop_back();
        plus.pop_back();
    }
    while (minus.size() >= 2)
    {
        answer += minus.back() * *(minus.rbegin() + 1);
        minus.pop_back();
        minus.pop_back();
    }
    if (!zero.empty() && !minus.empty())
    {
        minus.pop_back();
    }
    if (!minus.empty() && !plus.empty())
    {
        answer += minus.back() * plus.back() > minus.back() + plus.back() ?
        minus.back() * plus.back() : minus.back() + plus.back();
        minus.pop_back();
        plus.pop_back();
    }
    while (!minus.empty())
    {
        answer += minus.back();
        minus.pop_back();
    }
    while (!plus.empty())
    {
        answer += plus.back();
        plus.pop_back();
    }

    cout << answer;

    return 0;
}

/*1은 곱하는 게 아니라 무조건 더해줘야 한다는 것을 놓쳤다 ㅜㅜ*/
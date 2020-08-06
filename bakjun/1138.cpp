/* N명의 사람들은 매일 아침 한 줄로 선다. 이 사람들은 자리를 마음대로 서지 못하고 오민식의 지시대로 선다.

어느 날 사람들은 오민식이 사람들이 줄 서는 위치를 기록해 놓는다는 것을 알았다. 그리고 아침에 자기가 기록해 놓은 것과 사람들이 줄을 선 위치가 맞는지 확인한다.

사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지만을 기억한다. N명의 사람이 있고, 사람들의 키는 1부터 N까지 모두 다르다.

각 사람들이 기억하는 정보가 주어질 때, 줄을 어떻게 서야 하는지 출력하는 프로그램을 작성하시오. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool verify(vector<int> order, vector<int> people)
{
    vector<int>::iterator point = order.begin();
    int height = 1;
    while (point != order.end())
    {
        int count = 0;
        for (vector<int>::iterator i = people.begin(); *i != height; i++)
        {
            if (height < *i)
                ++count;
        }
        if (count != *point)
            return false;
        else
        {
            ++point;
            ++height;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> order;
    vector<int> people;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        order.insert(order.end(), temp);
    }
    for (int i = 1; i <= n; i++)
    {
        people.insert(people.end(), i);
    }

    while (true)
    {
        if (verify(order, people))
        {
            break;
        }
        else
        {
            next_permutation(people.begin(), people.end());
        }
    }

    for (vector<int>::iterator i = people.begin(); i != people.end(); i++)
    {
        cout << *i << ' ';
    }

    return 0;
}

/*나는 순열로 허접하게 풀었지만 다른 풀이들을 보면 전체적으로 이렇게 풀었다.
기본적으로 키가 제일 작은 사람부터 자기보다 큰 사람의 자리를 건너뛰고 세운다.
그 다음 키가 작은 사람도 그렇게 하되 만약 그 자리가 차 있다면 키가 작은 사람이
이미 앉은 자리이므로 자리가 날 때까지 이동해서 세운다.
이렇게 계속 반복하면 답이 나오게 돼 있다.*/
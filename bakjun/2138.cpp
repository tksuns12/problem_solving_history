/*N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는(1) 상태와 꺼져 있는 (0) 상태 중 하나의 상태를 가진다. i(1<i<N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.

N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(const vector<bool> &match1, const vector<bool> &match2, int count1, int count2)
{
    vector<bool> answer(2, false);
    for (bool var : match1)
    {
        if (var)
        {
            answer[0] = true;
            break;
        }
    }
    for (bool var : match2)
    {
        if (var)
        {
            answer[1] = true;
            break;
        }
    }
    if (!answer[0] && !answer[1])
    {
        cout << min(count1, count2);
    }
    else if (answer[0] && !answer[1])
    {
        cout << count2;
    }
    else if (!answer[0] && answer[1])
    {
        cout << count1;
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, count1 = 0, count2 = 0;
    string bulbs;
    string target;
    vector<bool> match1;
    vector<bool> match2;
    cin >> n;
    cin >> bulbs;
    cin >> target;

    for (int i = 0; i < n; ++i)
    {
        if (bulbs[i] == target[i])
        {
            match1.push_back(false);
            match2.push_back(false);
        }
        else
        {
            match1.push_back(true);
            match2.push_back(true);
        }
    }

    for (vector<bool>::iterator i = match1.begin(); i != match1.end(); ++i)
    {
        if (i == match1.begin())
        {
            *i = !*i;
            *(i + 1) = !(*(i + 1));
            ++count1;
        }
        else if (i + 1 == match1.end())
        {
            if (*(i - 1))
            {
                *(i - 1) = !(*(i - 1));
                *i = !*i;
                ++count1;
            }
        }
        else
        {
            if (*(i - 1))
            {
                *(i - 1) = !(*(i - 1));
                *i = !*i;
                *(i + 1) = !(*(i + 1));
                ++count1;
            }
        }
    }

    for (vector<bool>::iterator i = match2.begin(); i != match2.end(); ++i)
    {
        if (i == match2.begin())
        {
            continue;
        }
        else if (i + 1 == match2.end())
        {
            if (*(i - 1))
            {
                *(i - 1) = !(*(i - 1));
                *i = !*i;
                ++count2;
            }
        }
        else
        {
            if (*(i - 1))
            {
                *(i - 1) = !(*(i - 1));
                *i = !*i;
                *(i + 1) = !(*(i + 1));
                ++count2;
            }
        }
    }

    output(match1, match2, count1, count2);

    return 0;
}
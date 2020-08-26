/*민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB

이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 이때, '.'는 폴리오미노로 덮으면 안 된다.

폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validate(int a, string &answer)
{
    while (a > 0)
    {
        if (a % 2 != 0)
        {
            return false;
        }
        else if (a > 2)
        {
            a -= 4;
            answer += "AAAA";
        }
        else if (a == 2)
        {
            a -= 2;
            answer += "BB";
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string board;
    vector<int> repres;
    string answer = "";
    int sum = 0;
    cin >> board;

    char now = board[0];
    bool x = board[0] == 'X' ? true : false;

    for (char c : board)
    {
        if (c == now)
        {
            ++sum;
        }
        else
        {
            repres.push_back(sum);
            sum = 1;
            now = c;
        }
    }
    repres.push_back(sum);

    vector<int>::iterator p = repres.begin();

    while (p != repres.end())
    {
        if (x)
        {
            int cells = *p;
            if (validate(cells, answer))
            {
                ++p;
                x = !x;
            }
            else
            {
                answer = "no";
                break;
            }
        }
        else
        {
            for (int i = 0; i < *p; ++i)
            {
                answer += '.';
            }
            x = !x;
            ++p;
        }
    }

    if (answer == "no")
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}
// 2진수를 8진수로 바꾸는 문제

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string bc;

    cin >> bc;

    int first = bc.length() % 3;

    if (first == 0)
    {
        for (int i = 0; i < bc.length(); i += 3)
        {
            cout << (bc[i] - '0') * 4 + (bc[i + 1] - '0') * 2 + (bc[i + 2] - '0');
        }
    }
    else
    {
        if (first == 2)
        {
            cout << (bc[0] - '0') * 2 + (bc[1] - '0');
            for (int i = 2; i < bc.length(); i += 3)
            {
                cout << (bc[i] - '0') * 4 + (bc[i + 1] - '0') * 2 + (bc[i + 2] - '0');
            }
        }
        else
        {
            cout << (bc[0] - '0');
            for (int i = 1; i < bc.length(); i += 3)
            {
                cout << (bc[i] - '0') * 4 + (bc[i + 1] - '0') * 2 + (bc[i + 2] - '0');
            }
        }
    }
}

// 수가 너무 큰 것은 애초에 받아낼 수가 없기 때문에 string으로 받아서 처리하는 게 낫다.
// 정수 문자인 char에서 int 48이나 char '0'을 빼주면 바로 int로 타입 캐스팅을 할 수 있다.
// 8진수를 2진수로 변환하는 문제

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void print_binary(int a, bool isfirst)
{
    string result;
    while (a >= 2)
    {
        string mod = to_string(a % 2);
        result.append(mod);
        a /= 2;
    }
    result.append(to_string(a));
    while (result.length() != 3)
    {
        result.append(to_string(0));
    }
    while (isfirst && result.back() == '0')
    {
        result.pop_back();
    }

    while (!result.empty())
    {
        cout << result.back();
        result.pop_back();
    }
}

int main()
{
    string o;
    cin >> o;
    if (o == "0")
    {
        cout << '0';
    }
    else
    {
        for (int i = 0; i < o.length(); i++)
        {
            print_binary(o[i] - '0', i == 0);
        }
    }
}
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printResult(std::stack<char> &left, std::stack<char> &right)
{
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        printf("%c", right.top());
        right.pop();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    std::string str;
    std::stack<char> left;
    std::stack<char> right;
    int m;
    std::string order;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        left.push(str[i]);
    }
    cin >> m;
    cin.ignore();

    while (m--)
    {
        order.clear();
        getline(cin, order);
        if (order[0] == 'L' && !left.empty())
        {
            right.push(left.top());
            left.pop();
        }
        if (order[0] == 'D' && !right.empty())
        {
            left.push(right.top());
            right.pop();
        }
        if (order[0] == 'B' && !left.empty())
        {
            left.pop();
        }
        if (order[0] == 'P' && order[2] != '\0')
        {
            left.push(order[2]);
        }
    }

    printResult(left, right);
}
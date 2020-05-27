#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
using std::string;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    int num;
    stack<char> charStack;
    cin >> num;
    cin.ignore();

    while (num--)
    {
        getline(cin, input);
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != ' ')
            {
                charStack.push(input[i]);
            }
            else
            {
                while (!charStack.empty())
                {
                    cout << charStack.top();
                    charStack.pop();
                }
                cout << ' ';
            }
        }
        while (!charStack.empty())
        {
            cout << charStack.top();
            charStack.pop();
        }
        cout <<  '\n';
    }
}
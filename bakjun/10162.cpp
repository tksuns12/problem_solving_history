#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int a = 0;
    int b = 0;
    int c = 0;
    bool answer = true;

    while (t > 0)
    {
        if (t >= 300)
        {
            t -= 300;
            ++a;
        }
        else if (t >= 60)
        {
            t -= 60;
            ++b;
        }
        else if (t >= 10)
        {
            t -= 10;
            ++c;
        }
        else
        {
            answer = false;
            break;
        }
    }
    if (answer)
        cout << a << ' ' << b << ' ' << c;
    else
        cout << -1;
}
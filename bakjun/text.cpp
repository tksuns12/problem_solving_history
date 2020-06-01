#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int b;

    cin >> b;

    string bc = to_string(b);

    cout << (bc[0] - '0')*4;
}
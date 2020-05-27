#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // Make cin and cout as fast as scanf and printf
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a;
    int b;
    cin >> a >> b;
    cout << a + b;
}
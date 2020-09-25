#include <iostream>

using namespace std;

// n의 분해합이 target과 같은지 다른지 판단하는 함수
int is_generator(int n)
{

    int digit = 1;
    int temp = n;
    int answer = n;
    while(temp)
    {
        answer += temp % 10;
        temp /= 10;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    bool found = false;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        if (is_generator(i) == n)
        {
            cout << i;
            found = true;
            break;
        }
    }

    if (!found)
        cout << 0;

    return 0;
}
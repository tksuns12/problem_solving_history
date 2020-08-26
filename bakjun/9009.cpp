/*피보나치 수 ƒK는 ƒK = ƒK-1 + ƒK-2로 정의되며 초기값은 ƒ0 = 0과 ƒ1 = 1 이다. 양의 정수는 하나 혹은 그 이상의 서로 다른 피보나치 수들의 합으로 나타낼 수 있다는 사실은 잘 알려져 있다. 

하나의 양의 정수에 대한 피보나치 수들의 합은 여러 가지 형태가 있다. 예를 들어 정수 100은 ƒ4 + ƒ6 + ƒ11 = 3 + 8 + 89 또는 ƒ1 + ƒ3 + ƒ6 + ƒ11 = 1 + 2 + 8 + 89, 또는 ƒ4 + ƒ6 + ƒ9 + ƒ10 = 3 + 8 + 34 + 55 등으로 나타낼 수 있다. 이 문제는 하나의 양의 정수를 최소 개수의 서로 다른 피보나치 수들의 합으로 나타내는 것이다. 

하나의 양의 정수가 주어질 때, 피보나치 수들의 합이 주어진 정수와 같게 되는 최소 개수의 서로 다른 피보나치 수들을 구하라. */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> pibo;
        vector<int> answer;
        cin >> n;
        pibo.push_back(0);
        pibo.push_back(1);
        while (*pibo.rbegin() + *(pibo.rbegin() + 1) <= n)
        {
            pibo.push_back((*pibo.rbegin() + *(pibo.rbegin() + 1)));
        }
        vector<int>::reverse_iterator pointer = pibo.rbegin();
        while (n > 0 && pointer != pibo.rend())
        {
            if (n < *pointer)
                ++pointer;
            else
            {
                n -= *pointer;
                answer.insert(answer.begin(), *(pointer++));
            }
        }

        for (int n : answer)
        {
            cout << n << ' ';
        }
        cout << '\n';
    }
}
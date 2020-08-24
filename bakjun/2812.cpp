/*N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    vector<int> num_vec;
    num_vec.push_back(999999);
    for (char c : num)
    {
        int temp = c - '0';
        if (k == 0)
        {
            num_vec.push_back(temp);
            continue;
        }

        if (temp > num_vec.back())
        {
            int count = 0;
            for (int i = 0; i < k && !num_vec.empty() && num_vec.back() < temp; ++i)
            {
                count++;
                num_vec.pop_back();
            }
            num_vec.push_back(temp);
            k -= count;
        }
        else
        {
            num_vec.push_back(temp);
        }
    }

    while (k-- > 0)
    {
        num_vec.pop_back();
    }

    for (int i = 1; i < num_vec.size(); ++i)
    {
        cout << num_vec[i];
    }
    return 0;
}

/*스택을 통해 그리디하게 푸는 문제였다. ㅜㅜ*/
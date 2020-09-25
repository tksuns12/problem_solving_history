#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_hansu(int n)
{
    if (n < 100)
        return true;
    vector<int> nums;
    while (n > 0)
    {
        nums.push_back(n % 10);
        n /= 10;
    }

    int diff = nums[1] - nums[0];

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] != diff)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, answer = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (is_hansu(i))
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
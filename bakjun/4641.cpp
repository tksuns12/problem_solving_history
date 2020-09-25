/*2~15개의 서로 다른 자연수로 이루어진 리스트가 있을 때, 이들 중 리스트 안에 자신의 정확히 2배인 수가 있는 수의 개수를 구하여라.

예를 들어, 리스트가 "1 4 3 2 9 7 18 22"라면 2가 1의 2배, 4가 2의 2배, 18이 9의 2배이므로 답은 3이다.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int answer = 0;
    vector<int> nums;
    while (true)
    {
        

        int temp;
        cin >> temp;
        if (temp == -1)
            break;
        if (temp == 0)
        {
            sort(nums.begin(), nums.end());
            for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
            {
                for (vector<int>::iterator j = i + 1; j != nums.end(); j++)
                {
                    if (2 * (*i) == *j)
                    {
                        answer++;
                        break;
                    }
                }
            }

            cout << answer << '\n';
            nums.clear();
            answer = 0;
            continue;
        }
        nums.push_back(temp);
    }

    return 0;
}
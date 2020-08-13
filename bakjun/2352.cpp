#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> lis;
    lis.push_back(0);
    
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        if (lis.back() < temp) {
            lis.push_back(temp);
        } else {
            vector<int>::iterator low = lower_bound(lis.begin(), lis.end(), temp);
            *low = temp;
        }
    }

    cout << lis.size()-1;

    return 0;
}

/* 나는 접근 방법 자체가 좀 이상했고.. 아마 그렇게 했으면 시간 초과로 못 풀었을 것 같다.
이것은 전형적인 LIS 문제인데 그것을 간파하지 못했다.
LIS 문제는 이진탐색으로 이런 식으로 푸는 것이 가장 빠른 방법이다.
문제를 많이 풀어 패턴에 익숙해져야겠다.
*/
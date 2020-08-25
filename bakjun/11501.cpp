/*홍준이는 요즘 주식에 빠져있다. 그는 미래를 내다보는 눈이 뛰어나, 날 별로 주가를 예상하고 언제나 그게 맞아떨어진다. 매일 그는 아래 세 가지 중 한 행동을 한다.

주식 하나를 산다.
원하는 만큼 가지고 있는 주식을 판다.
아무것도 안한다.
홍준이는 미래를 예상하는 뛰어난 안목을 가졌지만, 어떻게 해야 자신이 최대 이익을 얻을 수 있는지 모른다. 따라서 당신에게 날 별로 주식의 가격을 알려주었을 때, 최대 이익이 얼마나 되는지 계산을 해달라고 부탁했다.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long answer = 0;
        int max = -99999999;
        vector<int> prices;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            prices.push_back(temp);
        }

        for (vector<int>::reverse_iterator i = prices.rbegin(); i != prices.rend(); ++i)
        {
            if (*i > max)
            {
                max = *i;
                continue;
            }
            else
            {
                answer += max - *i;
            }
        }

        cout << answer << '\n';
    }
}

/*앞에 있는 더 비싸지는 날은 반드시 그 이전 수들에 대해서 최종적으로 팔아야 하는 날이 되는 것을 캐치해야 한다. 뒤에 더 비싸지는 날이 있으면 그것은 그냥 그 이전 수들에 대해 파는 날이 되는 것이다. 그래서 뒤에서부터 파는 날을 체크하면 빠르다.*/
/*하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다. 이 저울의 양 팔의 끝에는 물건이나 추를 올려놓는 접시가 달려 있고, 양팔의 길이는 같다. 또한, 저울의 한쪽에는 저울추들만 놓을 수 있고, 다른 쪽에는 무게를 측정하려는 물건만 올려놓을 수 있다.
무게가 양의 정수인 N개의 저울추가 주어질 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구하는 프로그램을 작성하시오.

예를 들어, 무게가 각각 3, 1, 6, 2, 7, 30, 1인 7개의 저울추가 주어졌을 때, 이 추들로 측정할 수 없는 양의 정수 무게 중 최솟값은 21이다. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;
    vector<int> weights;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());

    int sum = 0;

    if (weights[0] == 1)
    {
        for (vector<int>::iterator i = weights.begin(); i != weights.end(); ++i)
        {
            sum += *i;
            if (*(i + 1) > sum + 1)
                break;
        }
    }

    cout << sum + 1;

    return 0;
}

/*해결책을 거의 생각을 다 해냈는데 또 둘러가버렸다. 제일 처음부터 작은 것부터 올려가며 하는 것을 케이스 체크했는데 정신력 소모를 이미 많이 했는지 케이스체크를 하며 이거 안 되는데? 하고 말았다.*/
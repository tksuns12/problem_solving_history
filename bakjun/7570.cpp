/*대한 어린이집에 올해 입학한 어린이들이 놀이터에 한 줄로 서있다. 모든 어린이들에게는 입학할 때 주어진 번호가 있고 모두 옷에 번호표를 달고 있다. 그런데 어린이들은 아직 번호 순서대로 줄을 잘 서지 못하므로 선생님이 다음과 같은 방법을 사용해서 번호순서대로 줄을 세우려고 한다.

방법: 줄 서있는 어린이 중 한 명을 선택하여 제일 앞이나 제일 뒤로 보낸다.

위의 방법을 사용할 때 어린이가 이동해서 빈자리가 생기는 경우에는 빈자리의 뒤에 있는 어린이들이 한 걸음씩 앞으로 걸어와서 빈자리를 메꾼다.

예를 들어, 5명의 어린이들에게 1부터 5까지의 번호가 주어져 있고, 다음과 같은 순서로 줄 서있다고 하자. 

5 2 4 1 3

위 방법을 이용해서 다음과 같이 번호순서대로 줄을 세울 수 있다. 

1번 어린이를 제일 앞으로 보낸다. (5 2 4 1 3 → 1 5 2 4 3)
4번 어린이를 제일 뒤로 보낸다. (1 5 2 4 3 → 1 5 2 3 4)
5번 어린이를 제일 뒤로 보낸다. (1 5 2 3 4 → 1 2 3 4 5)
위의 예에서는 세 명의 어린이를 제일 앞이나 제일 뒤로 보내 번호순서대로 줄을 세웠다. 그리고 두 명 이하의 어린이를 제일 앞이나 제일 뒤로 보내는 방법으로는 번호순서대로 줄을 세울 수 없다. 그러므로 이 경우에는 최소한 세 명의 어린이를 이동하여야 번호순서대로 줄을 세울 수 있다.

이 문제는 처음에 줄서있는 상태에서 위 방법을 이용해서 번호순서대로 줄을 세울 때 앞이나 뒤로 보내는 어린이 수의 최솟값을 찾는 것이다.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int mx = -9999999999;
    cin >> n;
    vector<int> d(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        d[temp] = d[temp - 1] + 1;
        mx = mx < d[temp] ? d[temp] : mx;
    }

    int answer = n - mx;

    cout << answer;

    return 0;
}

/*뭔가 가장 긴 증가하는 수열을 찾아야겠다는 생각은 들었는데 그게 연속하는 가장 긴 증가하는 수열인 줄은 꿈에도 몰랐다.
그렇다면 DP 문제에 더 가까운 것 같다.*/
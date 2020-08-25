/*스타박스는 손님을 입장시킬 때 독특한 방법으로 입장시킨다.

스타박스에서는 손님을 8시가 될 때 까지, 문앞에 줄 세워 놓는다. 그리고 8시가 되는 순간 손님들은 모두 입구에서 커피를 하나씩 받고, 자리로 간다. 강호는 입구에서 커피를 하나씩 주는 역할을 한다.

손님들은 입구에 들어갈 때, 강호에게 팁을 준다. 손님들은 자기가 커피를 몇 번째 받는지에 따라 팁을 다른 액수로 강호에게 준다. 각 손님은 강호에게 원래 주려고 생각했던 돈 - (받은 등수 - 1) 만큼의 팁을 강호에게 준다. 만약, 위의 식으로 나온 값이 음수라면, 강호는 팁을 받을 수 없다.

예를 들어, 민호는 팁을 3원 주려고 했고, 재필이는 팁을 2원, 주현이가 팁을 1원 주려고 한 경우를 생각해보자.

민호, 재필, 주현이 순서대로 줄을 서있다면, 민호는 강호에게 3-(1-1) = 3원, 재필이는 2-(2-1) = 1원, 주현이는 1-(3-1) = -1원을 팁으로 주게 된다. 주현이는 음수이기 때문에, 강호에게 팁을 주지 않는다. 따라서, 강호는 팁을 3+1+0=4원을 받게 된다.

스타박스 앞에 있는 사람의 수 N과, 각 사람이 주려고 생각하는 팁이 주어질 때, 손님의 순서를 적절히 바꿨을 때, 강호가 받을 수 잇는 팁의 최댓값을 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> peop;
    long long answer = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        peop.push_back(temp);
    }

    sort(peop.begin(), peop.end(), cmp);

    for (int i = 0; i < n; ++i)
    {
        if (peop[i] - i > 0)
        {
            answer += peop[i] - i;
        }
        else
            break;
    }

    cout << answer;
}
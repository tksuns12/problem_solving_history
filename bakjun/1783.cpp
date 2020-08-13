/*
병든 나이트가 N × M 크기 체스판의 가장 왼쪽아래 칸에 위치해 있다. 병든 나이트는 건강한 보통 체스의 나이트와 다르게 4가지로만 움직일 수 있다.

2칸 위로, 1칸 오른쪽
1칸 위로, 2칸 오른쪽
1칸 아래로, 2칸 오른쪽
2칸 아래로, 1칸 오른쪽
병든 나이트는 여행을 시작하려고 하고, 여행을 하면서 방문한 칸의 수를 최대로 하려고 한다. 병든 나이트의 이동 횟수가 4번보다 적지 않다면, 이동 방법을 모두 한 번씩 사용해야 한다. 이동 횟수가 4번보다 적은 경우(방문한 칸이 5개 미만)에는 이동 방법에 대한 제약이 없다.

체스판의 크기가 주어졌을 때, 병든 나이트가 여행에서 방문할 수 있는 칸의 최대 개수를 구해보자.*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int n, m;
    long long int answer;
    cin >> n >> m;

    if (n == 1)
    {
        answer = 1;
    }
    else if (n == 2)
    {
        answer = min(((m + 1) / 2), 4ll);
    }
    else if (m < 7)
    {
        answer = min(4ll, m);
    }
    else
    {
        answer = m - 2;
    }

    cout << answer;

    return 0;
}

/*거진 다 풀었는데 m의 조건 경계값을 뭘로 줄지 결정하는 부분에서 헷갈렸다.
4가지 동작을 모두 쓸 경우에 무조건 가로를 7칸 먹기 때문에 그 아래에서는 모두 쓰지 않아도 되는 것이다.*/
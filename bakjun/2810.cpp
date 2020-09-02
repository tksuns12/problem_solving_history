/*십년이면 강산이 변한다.

강산이네 동네에 드디어 극장이 생겼고, 강산이는 극장에 놀러갔다. 매점에서 콜라를 산 뒤, 자리에 앉은 강산이는 큰 혼란에 빠졌다. 양쪽 컵홀더를 이미 옆 사람들이 차지했기 때문에 콜라를 꽂을 컵 홀더가 없었기 때문이다. 영화를 보는 내내 콜라를 손에 들고 있던 강산이는 극장에 다시 왔을 때는 꼭 콜라를 컵 홀더에 놓겠다는 다짐을 한 후 집에 돌아갔다.

극장의 한 줄에는 자리가 N개가 있다. 서로 인접한 좌석 사이에는 컵홀더가 하나씩 있고, 양 끝 좌석에는 컵홀더가 하나씩 더 있다. 또, 이 극장에는 커플석이 있다. 커플석 사이에는 컵홀더가 없다.

극장의 한 줄의 정보가 주어진다. 이때, 이 줄에 사람들이 모두 앉았을 때, 컵홀더에 컵을 꽂을 수 있는 최대 사람의 수를 구하는 프로그램을 작성하시오. 모든 사람은 컵을 한 개만 들고 있고, 자신의 좌석의 양 옆에 있는 컵홀더에만 컵을 꽂을 수 있다.

S는 일반 좌석, L은 커플석을 의미하며, L은 항상 두개씩 쌍으로 주어진다.*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string seats;
    string merged = "";
    char prev;

    cin >> n >> seats;

    for (int i = 0; i < n; i++)
    {
        if (seats[i] == 'S')
        {
            merged += 'S';
            prev = 'S';
        }
        else
        {
            if (prev != 'L')
            {
                merged += 'L';
                prev = 'L';
            }
            else
            {
                prev = 'C';
            }
        }
    }

    int cups = merged.size() + 1;
    int answer = (n <= cups) ? n : cups;

    cout << answer;

    return 0;
}

/*홀더의 개수를 묻는 게 아니라 컵을 꽂을 수 있는 사람 수를 묻는 문제였다 ㅜㅜ 거기서 헤맸다.*/
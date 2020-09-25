/*상근이는 기숙사 생활을 한다. 상근이의 방의 크기는 L*W 이다.

수업시간에 타일 채우기 경우의 수를 계산하던 상근이는 자신의 방도 1*1크기 타일로 채우려고 한다. 이때, 가장자리는 빨간색으로, 나머지는 갈색으로 채우려고 한다.

아래 그림은 상근이의 방의 크기가 4*3일 때 이다.



어느 날 상근이네 방에 하근이가 놀러왔다. 하근이는 아름다운 타일 배치에 감동받았다. 다시 방으로 돌아온 하근이는 빨간색과 갈색 타일의 개수는 기억했지만, 방의 크기는 기억해내지 못했다.

빨간색과 갈색 타일의 개수가 주어졌을 때, 상근이 방의 크기를 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int red, brown;
    bool found = false;

    cin >> brown >> red;

    vector<int> answer;

    for (int l = 1; l <= 10000 && !found; l++)
    {
        for (int w = 1; w <= 10000 && !found; w++)
        {
            if ((l - 2) * (w - 2) == red && 2 * (l + w) - 4 == brown)
            {
                answer.push_back(l);
                answer.push_back(w);
                found = true;
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (int i = 1; i >= 0; i--)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}
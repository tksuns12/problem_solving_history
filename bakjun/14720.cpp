/*영학이는 딸기우유, 초코우유, 바나나우유를 좋아한다.

입맛이 매우 까다로운 영학이는 자신만의 우유를 마시는 규칙이 있다.

맨 처음에는 딸기우유를 한 팩 마신다.
딸기우유를 한 팩 마신 후에는 초코우유를 한 팩 마신다.
초코우유를 한 팩 마신 후에는 바나나우유를 한 팩 마신다.
바나나우유를 한 팩 마신 후에는 딸기우유를 한 팩 마신다. 
영학이는 우유 축제가 열리고 있는 우유거리에 왔다. 우유 거리에는 우유 가게들이 일렬로 늘어서 있다.

영학이는 우유 거리의 시작부터 끝까지 걸으면서 우유를 사먹고자 한다.

각각의 우유 가게는 딸기, 초코, 바나나 중 한 종류의 우유만을 취급한다.

각각의 우유 가게 앞에서, 영학이는 우유를 사마시거나, 사마시지 않는다.

우유거리에는 사람이 많기 때문에 한 번 지나친 우유 가게에는 다시 갈 수 없다.

영학이가 마실 수 있는 우유의 최대 개수를 구하여라.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int milk_change(int index)
{
    if (index == 2)
        return 0;
    else
        return index + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, answer = 0;
    vector<int> stores;
    vector<int> milks = {0, 1, 2};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        stores.push_back(temp);
    }
    int index;

    for (vector<int>::iterator i = stores.begin(); i != stores.end(); i++)
    {
        if (answer == 0)
        {
            if (*i == 0)
            {
                answer++;
                index = 0;
            }
            else
                continue;
        }
        else
        {
            if (*i == milks[milk_change(index)])
            {
                answer++;
                index = milk_change(index);
            }
            else
                continue;
        }
    }

    cout << answer;
    return 0;
}
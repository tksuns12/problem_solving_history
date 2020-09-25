/*정보 초등학교 6학년 여학생들은 단체로 2박 3일 수학여행을 가기로 했다. 학생들이 묵을 숙소에는 방의 정원(방 안에 있는 침대 수)을 기준으로 세 종류의 방이 있으며, 같은 종류의 방들이 여러 개 있다. 정보 초등학교에서는 학생들에게 이 방들을 배정하되, 배정된 모든 방에 빈 침대가 없도록 하고자 한다.

예를 들어, 방의 종류가 5인실, 9인실, 12인실이고 6학년 여학생 전체가 113명 이라면, 5인실 4개, 9인실 5개, 12인실 4개를 예약하면 각 방에 남는 침대 없이 배정이 가능하다. 또한 12인실은 사용하지 않고 5인실 10개와 9인실 7개만 사용하는 것도 가능하다. 그러나 방의 종류가 3인실, 6인실, 9인실이고 6학년 여학생 전체가 112명이라면 빈 침대 없이 방을 배정하는 것은 불가능하다.

방의 정원을 나타내는 서로 다른 세 자연수와 전체 학생 수를 나타내는 자연수 하나가 주어졌을 때, 배정된 모든 방에 빈 침대가 없도록 방 배정이 가능한지를 결정하는 프로그램을 작성하시오. 단, 세 종류의 방은 모두 충분한 개수가 있다고 가정하며, 위의 예에서와 같이 세 종류의 방을 모두 활용하지 않고 한 종류 또는 두 종류의 방만 이용하여 배정하는 것도 허용한다.*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> rooms;
    bool found = false;

    for (int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        rooms.push_back(temp);
    }

    cin >> n;

    for (int a = 0; a <= 300 && !found; a++)
    {
        for (int b = 0; b <= 300 && !found; b++)
        {
            for (int c = 0; c <= 300 && !found; c++)
            {
                int sum = a * rooms[0] + b * rooms[1] + c * rooms[2];
                if (sum == n)
                {
                    found = true;
                }
            }
        }
    }

    if (found)
        cout << 1;
    else
        cout << 0;

    return 0;
}
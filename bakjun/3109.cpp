/*유명한 제빵사 김원웅은 빵집을 운영하고 있다. 원웅이의 빵집은 글로벌 재정 위기를 피해가지 못했고, 결국 심각한 재정 위기에 빠졌다.

원웅이는 지출을 줄이고자 여기저기 지출을 살펴보던 중에, 가스비가 제일 크다는 것을 알게되었다. 따라서 원웅이는 근처 빵집의 가스관에 몰래 파이프를 설치해 훔쳐서 사용하기로 했다.

빵집이 있는 곳은 R*C 격자로 표현할 수 있다. 첫째 열은 근처 빵집의 가스관이고, 마지막 열은 원웅이의 빵집이다.

원웅이는 가스관과 빵집을 연결하는 파이프를 설치하려고 한다. 빵집과 가스관 사이에는 건물이 있을 수도 있다. 건물이 있는 경우에는 파이프를 놓을 수 없다.

가스관과 빵집을 연결하는 모든 파이프라인은 첫째 열에서 시작해야 하고, 마지막 열에서 끝나야 한다. 각 칸은 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 연결할 수 있고, 각 칸의 중심끼리 연결하는 것이다.

원웅이는 가스를 되도록 많이 훔치려고 한다. 따라서, 가스관과 빵집을 연결하는 파이프라인을 여러 개 설치할 것이다. 이 경로는 겹칠 수 없고, 서로 접할 수도 없다. 즉, 각 칸을 지나는 파이프는 하나이어야 한다.

원웅이 빵집의 모습이 주어졌을 때, 원웅이가 설치할 수 있는 가스관과 빵집을 연결하는 파이프라인의 최대 개수를 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    vector<vector<char>> way;
    int answer = 0;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        string temp;
        cin >> temp;
        vector<char> temp1;
        for (char c : temp)
        {
            temp1.push_back(c);
        }
        way.push_back(temp1);
    }
    for (int i = 0; i < r; i++)
    {
        vector<pair<int, int>> cand;
        bool quit = false;
        pair<int, int> pos = make_pair(i, 0);
        while (!quit)
        {
            if (pos.first == 0)
            {
                if (way[pos.first + 1][pos.second + 1] != 'x')
                    cand.push_back(make_pair(pos.first + 1, pos.second + 1));
                if (way[pos.first][pos.second + 1] != 'x')
                    cand.push_back(make_pair(pos.first, pos.second + 1));
            }
            else if (pos.first == r - 1)
            {
                if (way[pos.first][pos.second + 1] == '.')
                    cand.push_back(make_pair(pos.first, pos.second + 1));
                if (way[pos.first - 1][pos.second + 1] == '.')
                    cand.push_back(make_pair(pos.first - 1, pos.second + 1));
            }
            else
            {
                if (way[pos.first + 1][pos.second + 1] == '.')
                    cand.push_back(make_pair(pos.first + 1, pos.second + 1));
                if (way[pos.first][pos.second + 1] == '.')
                    cand.push_back(make_pair(pos.first, pos.second + 1));
                if (way[pos.first - 1][pos.second + 1] == '.')
                    cand.push_back(make_pair(pos.first - 1, pos.second + 1));
            }

            if (pos.second == c - 1)
            {
                quit = true;
                answer++;
            }

            else if (pos.second != c - 1 && cand.empty())
                quit = true;

            else
            {
                pair<int, int> next = cand.back();
                cand.pop_back();
                pos = next;
                way[pos.first][pos.second] = 'x';
            }
        }
    }

    cout << answer;

    return 0;
}
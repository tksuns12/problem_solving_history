/*석환이는 아기다. 아기 석환이는 자연수가 쓰여져있는 카드를 갖고 다양한 놀이를 하며 노는 것을 좋아한다. 오늘 아기 석환이는 무슨 놀이를 하고 있을까? 바로 카드 합체 놀이이다!

아기 석환이는 자연수가 쓰여진 카드를 n장 갖고 있다. 처음에 i번 카드엔 ai가 쓰여있다. 카드 합체 놀이는 이 카드들을 합체하며 노는 놀이이다. 카드 합체는 다음과 같은 과정으로 이루어진다.

x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.
이 카드 합체를 총 m번 하면 놀이가 끝난다. m번의 합체를 모두 끝낸 뒤, n장의 카드에 쓰여있는 수를 모두 더한 값이 이 놀이의 점수가 된다. 이 점수를 가장 작게 만드는 것이 놀이의 목표이다.

아기 석환이는 수학을 좋아하긴 하지만, 아직 아기이기 때문에 점수를 얼마나 작게 만들 수 있는지를 알 수는 없었다(어른 석환이는 당연히 쉽게 알 수 있다). 그래서 문제 해결 능력이 뛰어난 여러분에게 도움을 요청했다. 만들 수 있는 가장 작은 점수를 계산하는 프로그램을 만들어보자.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<long long> cards;
    long long answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        long long temp;
        cin >> temp;
        cards.push_back(temp);
    }

    while (m--)
    {
        sort(cards.begin(), cards.end());
        long long merge = cards[0] + cards[1];
        cards[0] = merge;
        cards[1] = merge;
    }

    for (long long n:cards)
    {
        answer += n;
    }

    cout << answer;
}

/*우선순위큐를 사용했다면 더 빨리 풀 수 있었다.*/
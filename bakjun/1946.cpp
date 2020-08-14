/*언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.

그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < a.second;
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        int min = 999999;
        cin >> n;
        vector<pair<int, int>> score;
        vector<int> seleted;
        for (int j = 0; j < n; ++j)
        {
            int tempa, tempb;
            cin >> tempa >> tempb;
            score.push_back(make_pair(tempa, tempb));
        }
        sort(score.begin(), score.end());

        for (pair<int, int> var : score)
        {
            if (seleted.size() == 0)
            {
                seleted.push_back(var.second);
                min = var.second;
            }
            else
            {
                if (min < var.second)
                {
                    continue;
                }
                else
                {
                    min = var.second;
                    seleted.push_back(var.second);
                }
            }
        }

        cout << seleted.size() << '\n';
    }
}

/*아 이거를 lower_bound를 안 쓰고 그냥 최소값을 계속 업데이트 했으면 시간을 훨씬 줄일 수 있었을 텐데... ㅜㅜ
이렇게 해서 904ms에서 416ms로 줄였다.*/
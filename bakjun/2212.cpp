/*한국도로공사는 고속도로의 유비쿼터스화를 위해 고속도로 위에 N개의 센서를 설치하였다. 문제는 이 센서들이 수집한 자료들을 모으고 분석할 몇 개의 집중국을 세우는 일인데, 예산상의 문제로, 고속도로 위에 최대 K개의 집중국을 세울 수 있다고 한다.

각 집중국은 센서의 수신 가능 영역을 조절할 수 있다. 집중국의 수신 가능 영역은 고속도로 상에서 연결된 구간으로 나타나게 된다. N개의 센서가 적어도 하나의 집중국과는 통신이 가능해야 하며, 집중국의 유지비 문제로 인해 각 집중국의 수신 가능 영역의 길이의 합을 최소화해야 한다.

편의를 위해 고속도로는 평면상의 직선이라고 가정하고, 센서들은 이 직선 위의 한 기점인 원점으로부터의 정수 거리의 위치에 놓여 있다고 하자. 따라서, 각 센서의 좌표는 정수 하나로 표현된다. 이 상황에서 각 집중국의 수신 가능영역의 거리의 합의 최솟값을 구하는 프로그램을 작성하시오. 단, 집중국의 수신 가능영역의 길이는 0 이상이며 모든 센서의 좌표가 다를 필요는 없다.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    vector<int> cordi;
    vector<int> dist;
    cin >> n >> k;
    if (k < n)
    {
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            cordi.push_back(temp);
        }

        sort(cordi.begin(), cordi.end());

        for (int i = 0; i < n - 1; i++)
        {
            dist.push_back(cordi[i + 1] - cordi[i]);
        }

        sort(dist.begin(), dist.end());

        for (int i = 0; i < k - 1; i++)
        {
            dist.pop_back();
        }
        long long answer = 0;
        for (int a : dist)
        {
            answer += (long long)a;
        }
        cout << answer;
    }
    else
    {
        long long answer = 0;
        cout << answer;
    }

    
    return 0;
}

/*이 문제는 송신국을 세울 때마다 가장 거리가 먼 곳끼리 커버치면서 가야 하는 문제였다. ㅜㅜ*/
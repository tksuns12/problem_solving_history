/*“반갑다. 내 이름은 반고흐#31555! 조선 최고의 활잡이지. 오늘도 난 금강산 위에서 적들을 노리고 있지. 내 앞에 있는 적들이라면 누구도 놓치지 않아! 좋아, 이제 곧 월식이 시작되는군. 월식이 시작되면 용이 적들을 집어삼킬 것이다. 잘 봐두어라! 마장동 활잡이 반고흐#31555님의 실력을-!”

반고흐#31555는 자기 뒤쪽 봉우리에 덩기#3958이 있음을 전혀 모르고 있었다. 덩기#3958도 반고흐#31555와 마찬가지로 월식이 시작되면 용을 불러내어 눈앞에 있는 다른 활잡이들을 모두 처치할 생각이다. 사실, 반고흐#31555와 덩기#3958 뿐만 아니라 금강 산맥의 N개 봉우리에 있는 모든 활잡이들이 같은 생각을 가지고 있다.

반고흐#31555가 있는 금강 산맥에는 총 N개의 봉우리가 있고, 모든 봉우리마다 한 명의 활잡이가 서서 월식이 시작되기만을 기다리고 있다. 다만, 애석하게도, 천계에 맥도날드가 생겨 용들이 살이 찐 탓에 용들은 자신보다 낮은 봉우리에 서있는 적들만 처치할 수 있게 되었다. 또한 용들은 처음 출발한 봉우리보다 높은 봉우리를 만나면 그대로 공격을 포기하고 금강산자락에 드러누워 낮잠을 청한다고 한다. 봉우리의 높이는 모두 다르고 모든 용들은 오른쪽으로만 나아가며, 중간에 방향을 틀거나, 봉우리가 무너지거나 솟아나는 경우는 없다.

“달에 마구니가 끼었구나.”

드디어 월식이 시작됐다! 과연 이들 활잡이 중 최고의 활잡이는 누구일까? 최고의 활잡이가 최대 몇 명의 적을 처치할 수 있는지 알아보자.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> summits;
    vector<int> kills;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        summits.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int kill = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (summits[i] > summits[j])
                kill++;
            else
                break;
        }
        kills.push_back(kill);
    }

    cout << *max_element(kills.begin(), kills.end());
}
/*오늘은 신승원의 생일이다.

박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 줬다.

공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.

공항에는 P개의 비행기가 순서대로 도착할 예정이며, 당신은 i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다. 비행기가 도킹된 게이트에는 다른 비행기가 도착할 수 없다.

이러한 사고가 일어나면 공항이 폐쇄되고, 이후 어떤 비행기도 도착할 수 없다.

신승원은 가장 많은 비행기를 공항에 도킹시켜서 박승원을 행복하게 하고 싶어한다. 승원이는 비행기를 최대 몇 대 도킹시킬 수 있는가?*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int g, p, answer = 0;
    vector<int> planes;
    cin >> g >> p;
    map<int, bool> gates;
    map<int, int> plan;

    for (int i = 0; i < p; i++)
    {
        int temp;
        cin >> temp;
        planes.push_back(temp);
        plan[temp] = 0;
    }

    for (int i = 1; i <= g; i++)
    {
        gates[i] = false;
    }

    for (int plane : planes)
    {
        bool docked = false;
        for (int i = plane - plan[plane]; i > 0; i--)
        {
            if (!gates[i])
            {
                plan[plane]++;
                docked = true;
                gates[i] = true;
                answer++;
                break;
            }
            else
                continue;
        }
        if (!docked)
            break;
    }

    cout << answer;

    return 0;
}

/*Union-find 혹은 Disjoint-set 자료구조를 사용하는 문제였다. 해당 링크는 https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html*/
/*우리는 사람의 덩치를 키와 몸무게, 이 두 개의 값으로 표현하여 그 등수를 매겨보려고 한다. 어떤 사람의 몸무게가 x kg이고 키가 y cm라면 이 사람의 덩치는 (x,y)로 표시된다. 두 사람 A 와 B의 덩치가 각각 (x,y), (p,q)라고 할 때 x>p 그리고 y>q 이라면 우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다. 예를 들어 어떤 A, B 두 사람의 덩치가 각각 (56,177), (45,165) 라고 한다면 A의 덩치가 B보다 큰 셈이 된다. 그런데 서로 다른 덩치끼리 크기를 정할 수 없는 경우도 있다. 예를 들어 두 사람 C와 D의 덩치가 각각 (45, 181), (55,173)이라면 몸무게는 D가 C보다 더 무겁고, 키는 C가 더 크므로, "덩치"로만 볼 때 C와 D는 누구도 상대방보다 더 크다고 말할 수 없다.

N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다. 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다. 이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다. 아래는 5명으로 이루어진 집단에서 각 사람의 덩치와 그 등수가 표시된 표이다.

이름	<몸무게, 키>	덩치 등수
A	<55, 185>	2
B	<58, 183>	2
C	<88, 186>	1
D	<60, 175>	2
E	<46, 155>	5
위 표에서 C보다 더 큰 덩치의 사람이 없으므로 C는 1등이 된다. 그리고 A, B, D 각각의 덩치보다 큰 사람은 C뿐이므로 이들은 모두 2등이 된다. 그리고 E보다 큰 덩치는 A, B, C, D 이렇게 4명이므로 E의 덩치는 5등이 된다. 위 경우에 3등과 4등은 존재하지 않는다. 여러분은 학생 N명의 몸무게와 키가 담긴 입력을 읽어서 각 사람의 덩치 등수를 계산하여 출력해야 한다.*/

#include <iostream>
#include <vector>

using namespace std;

struct Person
{
    int height;
    int weight;
    int rank;

    bool operator<(const Person &b)
    {
        return height < b.height && weight < b.weight;
    }

    bool operator>(const Person &b)
    {
        return height > b.height && weight > b.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<Person> people;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Person temp;
        cin >> temp.weight >> temp.height;
        people.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int ranking = 1;
        for (int j = 0; j < n; j++)
        {
            if (people[i] < people[j])
            {
                ranking++;
            }
        }
        people[i].rank = ranking;
    }

    for (int i = 0; i < n; i++)
    {
        cout << people[i].rank << ' ';
    }

    return 0;
}
/*어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b)
{

    return a > b;
}

int main()
{
    string n;
    cin >> n;
    int sum = 0;
    bool zero = false;
    vector<int> a;

    for (char c : n)
    {
        int temp = atoi(&c);
        if (temp == 0)
            zero = true;
        sum += temp;
        a.push_back(temp);
    }

    if (!zero || sum % 3 != 0)
    {
        cout << -1;
    }
    else
    {
        sort(a.begin(), a.end(), cmp);
        for (int num : a)
        {
            cout << num;
        }
    }

    return 0;
}

/*문제를 컴퓨터적으로 풀 것인가 논리적인 답이 바로 있는가 잘 생각해보아야겠다.*/
/*주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 위의 전개도를 수가 밖으로 나오게 접는다.

A, B, C, D, E, F에 쓰여 있는 수가 주어진다.

지민이는 현재 동일한 주사위를 N^3개 가지고 있다. 이 주사위를 적절히 회전시키고 쌓아서, N*N*N크기의 정육면체를 만들려고 한다. 이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.

N과 주사위에 쓰여 있는 수가 주어질 때, 보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.*/

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
    vector<int> cube(6);
    pair<long long, long long> mins = make_pair(1000, 1000);
    long long min;
    vector<pair<long long, long long>> double_pair = {
        make_pair(0, 1),
        make_pair(1, 5),
        make_pair(5, 4),
        make_pair(4, 0),
        make_pair(1, 2),
        make_pair(2, 4),
        make_pair(4, 3),
        make_pair(3, 1),
        make_pair(2, 0),
        make_pair(0, 3),
        make_pair(3, 5),
        make_pair(5, 2)};
    vector<vector<long long>> triple_pair = {
        {1, 3, 5},
        {1, 2, 5},
        {2, 4, 5},
        {3, 4, 5},
        {0, 1, 2},
        {0, 1, 3},
        {0, 3, 4},
        {0, 2, 4}};

    for (int i = 0; i < 6; ++i)
    {
        int temp;
        cin >> temp;
        cube[i] = temp;
    }

    long long answer = 0;

    if (n == 1)
    {
        int max = *max_element(cube.begin(), cube.end());
        int sum = 0;
        for (int var : cube)
        {
            sum += var;
        }
        answer = sum - max;
    }
    else
    {
        for (pair<long long, long long> var : double_pair)
        {
            if (mins.first > cube[var.first] + cube[var.second])
                mins.first = cube[var.first] + cube[var.second];
        }

        for (vector<long long> var : triple_pair)
        {
            if (mins.second > cube[var[0]] + cube[var[1]] + cube[var[2]])
                mins.second = cube[var[0]] + cube[var[1]] + cube[var[2]];
        }

        min = *min_element(cube.begin(), cube.end());
        long long n3 = 4;
        long long n2 = ((n - 2ll) * 4ll + (n - 1ll) * 4ll);
        long long n1 = ((n - 2ll) * (n - 2ll) + 4ll * (n - 2ll) * (n - 1ll));

        answer = mins.second * n3 + mins.first * n2 + min * n1;
    }
    cout << answer;

    return 0;
}

/*long long 형을 포함한 계산을 다시 long long에 넣어줄 때 정수 리터럴을 반드시 long long형으로 명시적 형변환을 해주어야 한다.*/
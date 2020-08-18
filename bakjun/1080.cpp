/*0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 -> 1, 1 -> 0)*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int output(const vector<vector<bool>> &mat, int m, int n, int answer)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j])
            {
                return -1;
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> mat1;
    vector<string> mat2;
    vector<vector<bool>> work(n, vector<bool>(m));
    int answer = 0;

    

    for (int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        mat1.push_back(temp);
    }

    for (int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        mat2.push_back(temp);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat1[i][j] != mat2[i][j])
                work[i][j] = true;
            else
                work[i][j] = false;
        }
    }

    if (m < 3 || n < 3)
        goto out;

    for (int i = 0; i <= n - 3; ++i)
    {
        for (int j = 0; j <= m - 3; ++j)
        {
            if (work[i][j])
            {
                for (int a = i; a < i + 3; ++a)
                {
                    for (int b = j; b < j + 3; ++b)
                    {
                        work[a][b] = !work[a][b];
                    }
                }
                ++answer;
            }
        }
    }
out:
    cout << output(work, m, n, answer);

    return 0;
}

/*말 그대로 완전히 그리디하게 노가다로 푸는 문제였다. 왼쪽 위부터 하나씩 바꿔가면서 하는 것. 대신에 3*3보다 행렬이 작으면 아예 연산 자체를 허용하지 않아야 풀 수 있다.*/
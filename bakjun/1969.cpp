/*DNA란 어떤 유전물질을 구성하는 분자이다. 이 DNA는 서로 다른 4가지의 뉴클레오티드로 이루어져 있다(Adenine, Thymine, Guanine, Cytosine). 우리는 어떤 DNA의 물질을 표현할 때, 이 DNA를 이루는 뉴클레오티드의 첫글자를 따서 표현한다. 만약에 Thymine-Adenine-Adenine-Cytosine-Thymine-Guanine-Cytosine-Cytosine-Guanine-Adenine-Thymine로 이루어진 DNA가 있다고 하면, “TAACTGCCGAT”로 표현할 수 있다. 그리고 Hamming Distance란 길이가 같은 두 DNA가 있을 때, 각 위치의 뉴클오티드 문자가 다른 것의 개수이다. 만약에 “AGCAT"와 ”GGAAT"는 첫 번째 글자와 세 번째 글자가 다르므로 Hamming Distance는 2이다.

우리가 할 일은 다음과 같다. n개의 길이가 같은 DNA가 주어져 있을 때(이 DNA를 a1a2a3a4...이라고 하자) Hamming Distance의 합이 가장 작은 DNA s를 구하는 것이다. 즉, s와 a1의 Hamming Distance + s와 a2의 Hamming Distance + s와 a3의 Hamming Distance ... 의 합이 최소가 된다는 의미이다.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int count_distance(string a, string b)
{
    int distance = 0;
    for (decltype(a.length()) i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) ++distance;
    }
    return distance;
}

int main()
{
    int n, m;
    vector<string> input;
    cin >> n >> m;
    vector<map<char, int>> most(m);
    string answer;
    int distance = 0;

    for(map<char, int> item : most)
    {
        item.insert(make_pair('A', 0));
        item.insert(make_pair('C', 0));
        item.insert(make_pair('G', 0));
        item.insert(make_pair('T', 0));
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        input.insert(input.end(), temp);
    }

    for (string dna : input)
    {
        for (int i = 0; i < m; i++)
        {
            most[i][dna[i]]++;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int max = -1;
        char a;
        for(pair<char, int> item : most[i])
        {
            if (max < item.second) {
                max = item.second;
                a = item.first;
            }
        }
        answer += a;
    }

    for (int i = 0; i < n; ++i)
    {
        distance += count_distance(answer, input[i]);
    }

    cout << answer << '\n' << distance;

    return 0;
}
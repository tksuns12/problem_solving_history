/*민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool cmp1(const string &a, const string &b)
{
    return a.size() > b.size();
}

bool cmp2(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second > b.second;
}

vector<pair<char, int>> maptopairs(const map<char, int> &a)
{
    vector<pair<char, int>> b;
    for (pair<char, int> var : a)
    {
        b.push_back(var);
    }
    sort(b.begin(), b.end(), cmp2);
    return b;
}

int tens(int base, int pow)
{
    if (pow == 0)
        return base;
    else
    {
        for (int i = 1; i <= pow; i++)
        {
            base *= 10;
        }
    }
    return base;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    sort(words.begin(), words.end(), cmp1);

    int max_length = words[0].size();
    map<char, vector<int>> char_counts;

    for (string s : words)
    {
        for (char c : s)
        {
            if (char_counts.find(c) == char_counts.end())
            {
                char_counts.insert(make_pair(c, vector<int>(max_length, 0)));
            }
        }
    }

    for (string s : words)
    {
        int i = max_length - s.size();

        for (char c : s)
        {
            ++char_counts[c][i++];
        }
    }

    map<char, int> final;

    for (pair<char, vector<int>> var : char_counts)
    {
        int pow = max_length - 1;
        for (int i = 0; i < var.second.size(); ++i)
        {
            if (final.find(var.first) == final.end())
            {
                final.insert(make_pair(var.first, tens(var.second[i], pow--)));
            }
            else
            {
                final[var.first] += tens(var.second[i], pow--);
            }
        }
    }

    vector<pair<char, int>> real_final = maptopairs(final);
    map<char, int> nums;
    int num = 9;
    for (pair<char, int> a : real_final)
    {
        nums.insert(make_pair(a.first, num--));
    }
    int answer = 0;

    for (string word : words)
    {
        int pow = word.size() - 1;
        for (char c : word)
        {
            answer += tens(nums[c], pow--);
        }
    }

    cout << answer;
}

/*너무 복잡하게 풀었다. ㅜㅜ 애초에 처음부터 자릿수를 세어서 1, 10을 곱해서 카운트를 했다면 (정직하게 카운트 하지 않고) for문을 한 번은 덜 썼어도 됐을 것이다.*/
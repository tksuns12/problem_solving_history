#include <iostream>

using namespace std;
using std::string;

string checker(string input)
{
    int numOfOpen = 0;
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] == '(')
        {
            ++numOfOpen;
        }
        if (input[i] == ')')
        {
            if (numOfOpen == 0)
            {
                return "NO";
            }
            --numOfOpen;
        }
    }

    if (numOfOpen == 0)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    int num;
    cin >> num;
    cin.ignore();
    while (num--)
    {
        getline(cin, input);
        cout << checker(input) << '\n';
    }
}

// #include<cstdio>
// int n;
// char s[51];
// int main() {
// 	scanf("%d", &n);
// 	for (int i = 0; i < n; i++) {
// 		scanf("%s", s);
// 		int c = 0;
// 		for (int j = 0; s[j] && c >= 0; j++) s[j] == '(' ? c++ : c--;
// 		puts(c ? "NO" : "YES");
// 	}
// 	return 0;
// }

// 우와... 삼항연산자를 이용해서 멋들어지게 풀어냈다. 메모리도 내 코드의 반밖에 안 썼다. for문의 조건식에는 어떠한 조건식도 들어갈 수 있다는 것을 잊지 말아야겠다.
// 그리고 더욱 깔쌈한 것은 스택이 0이 아니면 무조건 틀린 거란 것을 이용했다는 것이다!!! 아 깔쌈 초깔삼
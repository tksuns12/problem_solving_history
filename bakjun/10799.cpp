#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int stickNum = 0;
    int totalNum = 0;
    stack<char> s;
    char input[100000];
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
        {
            ++stickNum;
            ++totalNum;
            s.push(input[i]);
        }
        else
        {
            s.pop();
            if (input[i - 1] == '(')
            {
                --stickNum;
                --totalNum;
                totalNum += s.size();
            }
        }
    }

    printf("%d", totalNum);
}

// #include <stdio.h>

// int main() {
//     int a = 0, n = 0;
//     char c[100001];

//     scanf("%s", c);

//     for (int i = 0; c[i]; i++)
//         if (c[i] == '(')
//             n++;
//         else {
//             n--;
//             a += c[i - 1] == '(' ? n : 1;
//         }

//     printf("%d", a);
// }

// 내가 하고자 했던 걸 삼항 연산자를 이용해서 되게 간단하게 풀어낸 것 같다. 쩐다.
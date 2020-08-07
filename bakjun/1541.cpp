
/*
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.*/

#include <iostream>
#include <string>

using namespace std;

string input;

int main()
{
    cin >> input;
    int answer = 0;
    string temp = "";
    bool sub = false;

    for (string::iterator i = input.begin(); i != input.end(); ++i)
    {
        if (!isdigit(*i))
        {
            if (temp != "")
            {

                if (sub)
                    answer -= stoi(temp);
                else
                    answer += stoi(temp);
                temp = "";
            }
            if (*i == '-')
                sub = true;
        }
        else
        {
            temp += *i;
        }
    }
    if (sub)
        answer -= stoi(temp);
    else
        answer += stoi(temp);

    cout << answer;

    return 0;
}
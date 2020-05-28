#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    char input[100000];
    scanf("%[^\n]s", input);
    stack<char> str;
    char tagMarker = '\0';

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '<')
        {
            tagMarker = '<';
        }
        else if (input[i] == '>')
        {
            tagMarker = '>';
        }
        if (tagMarker == '<')
        {
            if (!str.empty())
            {
                while (!str.empty())
                {
                    printf("%c", str.top());
                    str.pop();
                }
            }
            printf("%c", input[i]);
        }
        else if (tagMarker == '>')
        {
            printf("%c", input[i]);
            tagMarker = '\0';
        }
        else
        {
            if (input[i] == ' ')
            {
                while (!str.empty())
                {
                    printf("%c", str.top());
                    str.pop();
                }
                printf("%c", ' ');
            }
            else
            {
                str.push(input[i]);
            }
        }
    }
    if (!str.empty())
    {
        while (!str.empty())
        {
            printf("%c", str.top());
            str.pop();
        }
    }
}
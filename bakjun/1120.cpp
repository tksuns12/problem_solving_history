/*
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.
*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int count_difference(string a, string b, int start)
{
    int count = 0;
    for (decltype(a.length()) i = start; i < start + a.length(); i++)
    {
        if (a[i-start] != b[i])
            ++count;
    }

    return count;
}

int main()
{
    string a;
    string b;

    cin >> a >> b;
    int min = 9999;

    for (decltype(a.length()) i = 0; i <= b.length() - a.length(); i++)
    {
        int difference = count_difference(a, b, i);
        if (min > difference)
        {
            min = difference;
        }
    }

    printf("%d", min);
}
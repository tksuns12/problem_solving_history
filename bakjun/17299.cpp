#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    static int freq[1000000];
    int series[n];
    int oken[n];
    stack<int> con;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &series[i]);
        freq[series[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (con.empty()) {
            con.push(i);
        } else {
            while(!con.empty() && freq[series[con.top()]]<freq[series[i]]){
                oken[con.top()] = series[i];
                con.pop();
            }
            con.push(i);
        }
    }

    while (!con.empty()) {
        oken[con.top()] = -1;
        con.pop();
    }

    for (int i =0; i < n; i++) {
        printf("%d", oken[i]);
        if (i != n-1) {
            printf("%c", ' ');
        }
    }
}
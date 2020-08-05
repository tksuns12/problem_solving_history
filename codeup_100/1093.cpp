#include <stdio.h>

int main()
{
    int stud[24] = {};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        stud[t]++;
    }

    for (int i = 1; i<=23; i++) {
        printf("%d ", stud[i]);
    }
}
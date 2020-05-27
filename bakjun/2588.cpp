#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a;
    int b;

    cin >> a;
    cin >> b;
    cout << a * (b % 10) << '\n';
    cout << a * ((b / 10) % 10) << '\n';
    cout << a * (b / 100) << '\n';
    cout << a * b;
}

// #include<stdio.h>

// int main()
// {
// 	int A = 0;
// 	int B = 0;
	
// 	scanf("%d", &A);
// 	scanf("%d", &B);

// 	printf("%d\n%d\n%d\n%d", A*(B%10),A*(B/10%10),A*(B/100),A*B);
// 	getchar();
	
	
// }
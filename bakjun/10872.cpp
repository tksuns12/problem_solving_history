// 팩토리얼 문제
#include <stdio.h>

int facto(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * facto(n-1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", facto(n));

}
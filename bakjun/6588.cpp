#include <stdio.h>

void showResult(int n, int *primeNums, bool *primeList)
{
    bool found;
    for (int i = 0; i < 1000000; i++)
    {
        int diff = n - primeNums[i];
        if (!primeList[diff])
        {
            printf("%d = %d + %d\n", n, primeNums[i], diff);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Goldbach's conjecture is wrong.\n");
    }
}

const int MAX = 1000000;

int main()
{
    bool *primeList = new bool[MAX+1];
    int* primeNums = new int[MAX];
    int pn = 0;
    int n;
    for (int i = 2; i <= MAX; i++)
    {
        if (primeList[i] == false)
        {
            primeNums[pn++] = i;
            for (int j = i * 2; j <= 1000000; j += i)
            {
                primeList[j] = true;
            }
        }
    }
    while (true)
    {

        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        showResult(n, primeNums, primeList);
    }
    delete[] primeList;
    delete[] primeNums;
}

// 여기서 배운 점은 재활용 가능한 것이라면 그 크기가 커도 한 번 만들어두는 게 더 낫다.
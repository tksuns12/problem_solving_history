/*Day Of Mourning의 기타리스트 강토가 사용하는 기타에서 N개의 줄이 끊어졌다. 따라서 새로운 줄을 사거나 교체해야 한다. 강토는 되도록이면 돈을 적게 쓰려고 한다. 6줄 패키지를 살 수도 있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.
끊어진 기타줄의 개수 N과 기타줄 브랜드 M개가 주어지고, 각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격, 낱개로 살 때의 가격이 주어질 때, 적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램을 작성하시오.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> set_price;
    vector<int> pic_price;

    int set_count = n / 6;
    int diff = n % 6;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        set_price.push_back(a);
        pic_price.push_back(b);
    }
    sort(set_price.begin(), set_price.end());
    sort(pic_price.begin(), pic_price.end());

    int answer = 0;

    if (n < 6)
    {
        if (*set_price.begin() > *pic_price.begin() * n)
            answer = *pic_price.begin() * n;
        else
            answer = *set_price.begin();
    }
    else
    {
        if (*set_price.begin() > *pic_price.begin() * 6)
            answer = *pic_price.begin() * n;
        else
        {
            answer += set_count * *set_price.begin();
            n -= set_count * 6;
            if (n > 0)
            {
                if (diff * *pic_price.begin() > *set_price.begin())
                    answer += *set_price.begin();
                else
                    answer += diff * *pic_price.begin();
            }
        }
    }

    cout << answer;
    return 0;
}

/*예외 케이스를 꼼꼼히 살피지 않아 계속 68퍼센트에서 틀렸다.*/
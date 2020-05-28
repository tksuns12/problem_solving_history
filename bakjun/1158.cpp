#include <iostream>
#include <list>

using namespace std;

void next(std::list<int>::iterator &iter, std::list<int> &table)
{
    if (iter == table.end())
    {
        iter = table.begin();
    }
    else if (++iter == table.end())
    {
        iter = table.begin();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    std::list<int> table;
    for (int i = 1; i <= n; i++)
    {
        table.push_back(i);
    }
    std::list<int>::iterator point = table.end();
    cout << '<';

    while (!table.empty())
    {
        for (int i = 0; i < k; i++)
        {
            next(point, table);
        }
        if (*point == table.back())
        {
            cout << table.back();
            table.erase(point--);
        }
        else
        {
            cout << *point;
            table.erase(point++);
            point--;
        }
        if (!table.empty())
        {
            cout << ", ";
        }
    }

    cout << '>';
}
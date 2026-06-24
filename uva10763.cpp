#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        /*
        unordered_map<int, unordered_map<int, int>> cand;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (cand[a].find(b) == cand[a].end())
                cand[a][b] = 1;
            else
                cand[a][b]++;
        }
        int exchange = 0;
        for (auto i : cand)
        {
            for (auto j : cand[i.first])
            {
                if (cand[i.first][j.first] == 0)
                    continue;
                if (cand[j.first].find(i.first) != cand[j.first].end() && cand[j.first][i.first] > 0)
                {
                    int available = min(cand[i.first][j.first], cand[j.first][i.first]);
                    cand[i.first][j.first] -= available;
                    cand[j.first][i.first] -= available;
                    exchange += 2 * available;
                }
            }
        }
        if (exchange == n)
            cout << "YES\n";
        else
            cout << "NO\n";
        */
        map<pair<int, int>, int> cand;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            cand[{a, b}]++;
        }
        int exchange = 0;
        for (auto i : cand)
        {
            int a = i.first.first;
            int b = i.first.second;
            if (cand[{b, a}] == i.second)
                exchange += i.second;
        }
        if (exchange == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
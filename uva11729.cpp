#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int CASE = 1;
    while (cin >> n && n)
    {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int b, j;
            cin >> b >> j;
            v[i] = {b, j};
        }
        sort(v.begin(), v.end(), cmp);
        int time1 = 0, time2 = 0;
        for (auto i : v)
        {
            time1 += i.first;
            if (time1 + i.second > time2)
            {
                time2 = time1 + i.second; // last done his job time
            }
        }
        cout << "Case " << CASE++ << ": " << time2 << "\n";
    }

    return 0;
}
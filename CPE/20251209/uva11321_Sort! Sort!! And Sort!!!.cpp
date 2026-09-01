#include <bits/stdc++.h>

using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        if (a.first % 2 != b.first % 2)
            return a.first % 2 == 1;
        else if (a.first % 2 == 1)
            return a.first > b.first;
        else if (a.first % 2 == 0)
            return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> v[i].first;
            v[i].second = v[i].first % m;
        }
        sort(v.begin(), v.end(), cmp);

        cout << n << " " << m << "\n";
        for (pair<int, int> x : v)
            cout << x.first << "\n";
    }
    cout << "0 0\n";

    return 0;
}
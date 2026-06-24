#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n != 0)
    {
        int cur_max = 0;
        map<vector<int>, int> c;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(5);
            for (int j = 0; j < 5; j++)
                cin >> tmp[j];
            sort(tmp.begin(), tmp.end());
            c[tmp]++;
            cur_max = max(cur_max, c[tmp]);
        }
        int ans = 0;
        for (auto i : c)
        {
            if (i.second == cur_max)
            {
                ans += cur_max;
            }
        }
        cout << ans << "\n";
        }

    return 0;
}
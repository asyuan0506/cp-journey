#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a && b)
        return gcd(b, a % b);
    return a + b;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cows(n);
        int days = 1;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            days = days / gcd(days, t) * t;
            for (int j = 0; j < t; j++)
            {
                int milk;
                cin >> milk;
                cows[i].push_back(milk);
            }
        }

        int killed = 0;
        int last_time = 0;
        for (int t = 0; t < last_time + days; t++)
        {
            int mn_idx = -1, mn = INT_MAX;
            bool same = false;
            if (cows.size() == 0)
                break;
            for (int i = 0; i < cows.size(); i++)
            {
                int cur = cows[i][t % cows[i].size()];
                if (cur < mn)
                {
                    mn_idx = i;
                    mn = cur;
                    same = false;
                }
                else if (cur == mn)
                    same = true;
            }
            if (!same)
            {
                killed++;
                last_time = t;
                cows.erase(cows.begin() + mn_idx);
            }
        }
        cout << n - killed << " ";
        if (killed)
            cout << last_time + 1 << "\n";
        else
            cout << "0\n";
    }

    return 0;
}
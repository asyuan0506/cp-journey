#include <bits/stdc++.h>

using namespace std;

const int OFFSET = 5000;
const int MAX_N = 10010;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v(n + m);
        int total = 0;
        for (int i = 0; i < n + m; i++)
        {
            cin >> v[i];
            total += v[i];
        }
        
        if (n < m)
            swap(n, m);

        vector<vector<bool>> dp(n + 1, vector<bool> (MAX_N, false));
        dp[0][OFFSET] = true;

        int processed = 0;
        for (int x : v)
        {
            for (int cnt = min(n - 1, processed); cnt >= 0; cnt--)
            {
                for (int now = 0; now < MAX_N; now++)
                {
                    if (!dp[cnt][now])
                        continue;
                    int new_sum = now + x;
                    dp[cnt + 1][new_sum] = true;
                }
            }
            processed++;
        }

        int mx = INT_MIN, mn = INT_MAX;
        for (int now = 0; now < MAX_N; now++)
        {
            if (dp[n][now])
            {
                int res = (now - OFFSET) * (total + OFFSET - now);
                mx = max(mx, res);
                mn = min(mn, res);
            }
        }

        cout << mx << " " << mn << "\n";
    }


    return 0;
}
#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main()
{
    int T;
    cin >> T;
    int Case = 0;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 1 || k == 0)
        {
            cout << "Case " << ++Case << ": 0\n";
            continue;
        }
        

        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (n/2 + 1, vector<ll> (k, 0)));
        // [lens][number of 1s][rem]
        dp[1][1][1 % k] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= n / 2; j++)
            {
                for (int rem = 0; rem < k; rem++)
                {
                    dp[i + 1][j][rem * 2 % k] += dp[i][j][rem];
                    if (j < n / 2)
                        dp[i + 1][j + 1][(rem * 2 + 1) % k] += dp[i][j][rem];
                }
            }
        }
        cout << "Case " << ++Case << ": " << dp[n][n / 2][0] << "\n";
    }

    return 0;
}
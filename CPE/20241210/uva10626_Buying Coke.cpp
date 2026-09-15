#include <bits/stdc++.h>

using namespace std;

int Buy(int n, int n1, int n5, int n10, vector<vector<vector<int>>> &dp)
{
    // 1. 10 -> 1x2
    // 2. 5 + 1 + 1 + 1
    // 3. 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
    // 4. 5 + 5 -> 1x2
    // 5. 10 + 1 + 1 + 1 -> 5
    if (n == 0)
        return 0;
    if (dp[n1][n5][n10] != INT_MAX)
        return dp[n1][n5][n10];
    if (n10 > 0)
    {
        dp[n1][n5][n10] = min(dp[n1][n5][n10], Buy(n - 1, n1 + 2, n5, n10 - 1, dp) + 1);
    }
    if (n5 > 0 && n1 >= 3)
    {
        dp[n1][n5][n10] = min(dp[n1][n5][n10], Buy(n - 1, n1 - 3, n5 - 1, n10, dp) + 4);
    }
    if (n1 >= 8)
    {
        dp[n1][n5][n10] = min(dp[n1][n5][n10], Buy(n - 1, n1 - 8, n5, n10, dp) + 8);
    }
    if (n5 >= 2)
    {
        dp[n1][n5][n10] = min(dp[n1][n5][n10], Buy(n - 1, n1 + 2, n5 - 2, n10, dp) + 2);
    }
    if (n10 > 0 && n1 >= 3)
    {
        dp[n1][n5][n10] = min(dp[n1][n5][n10], Buy(n - 1, n1 - 3, n5 + 1, n10 - 1, dp) + 4);
    }
    return dp[n1][n5][n10];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int cokes;
        cin >> cokes;
        vector<int> coins(3);
        for (int i = 0; i < 3; i++)
            cin >> coins[i];
        
        vector<vector<vector<int>>> dp(801, vector<vector<int>> (151, vector<int> (51, INT_MAX)));
        int ans = Buy(cokes, coins[0], coins[1], coins[2], dp);


        cout << ans << "\n";
    }


    return 0;
}
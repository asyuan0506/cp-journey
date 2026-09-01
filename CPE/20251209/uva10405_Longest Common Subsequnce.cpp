#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    while (getline(cin, s1))
    {
        getline(cin, s2);
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for (int i = 1; i <= s1.length(); i++)
        {
            for (int j = 1; j <= s2.length(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[s1.length()][s2.length()] << "\n";
        // int i = s1.length(), j = s2.length();
        // string ans = "";
        // while (i > 0 && j > 0)
        // {
        //     if (s1[i - 1] == s2[j - 1])
        //     {
        //         i--; j--;
        //         ans += s1[i];
        //     }
        //     else if (dp[i - 1][j] > dp[i][j - 1])
        //     {
        //         i--;
        //     }
        //     else
        //     {
        //         j--;
        //     }
        // }
        // reverse(ans.begin(), ans.end());
        // cout << ans << "\n";
    }

    return 0;
}
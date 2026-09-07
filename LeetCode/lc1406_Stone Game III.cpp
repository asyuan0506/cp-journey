class Solution {
public:
    // int max_diff(int idx, vector<int>& v, vector<int>& dp)
    // {
    //     if (idx == v.size() - 1) return 0;
    //     if (dp[idx + 1] != INT_MIN) return dp[idx + 1];
    //     int mx = INT_MIN;
    //     int sum = 0;
    //     for (int i = 1; i <= 3 && idx + i < v.size(); i++)
    //     {
    //         sum += v[idx + i];
    //         mx = max(mx, sum - max_diff(idx + i, v, dp));
    //     }
    //     dp[idx + 1] = mx;
    //     return mx;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     vector<int> dp(stoneValue.size(), INT_MIN);
    //     int res = max_diff(-1, stoneValue, dp);
    //     if (res > 0)
    //         return "Alice";
    //     else if (res == 0)
    //         return "Tie";
    //     else
    //         return "Bob";
    // }

    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        int dp[4] = { 0, 0, 0, 0 }; // max_diff
        for (int i = stoneValue.size() - 1; i >= 0; i--)
        {
            dp[i % 4] = stoneValue[i] - dp[(i + 1) % 4];
            if (i + 1 < n)
                dp[i % 4] = max(dp[i % 4], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4]);
            if (i + 2 < n)
                dp[i % 4] = max(dp[i % 4], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3)% 4]);
        }
        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] == 0)
            return "Tie";
        else
            return "Bob";
    }
};
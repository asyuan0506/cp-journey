// Similar to lc486_Predict the Winner

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = piles[i];
            for (int j = i + 1; j < n; j++)
            {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};
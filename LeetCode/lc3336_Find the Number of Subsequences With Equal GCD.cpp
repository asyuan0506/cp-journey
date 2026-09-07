constexpr int MOD = 1000000007;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        const int n = nums.size();

        vector<vector<int>> dp(m + 1, vector<int> (m + 1, 0));
        dp[0][0] = 1;
        for (int num : nums)
        {
            vector<vector<int>> new_dp(m + 1, vector<int> (m + 1, 0));
            for (int j = 0; j <= m; j++)
            {
                int g1 = gcd(j, num);
                for (int k = 0; k <= m; k++)
                {
                    int g2 = gcd(k, num);
                    int ways = dp[j][k];
                    // 1. Don't add num into either seq1 or seq2
                    new_dp[j][k] = (new_dp[j][k] + ways) % MOD;
                    // 2. Add num into seq1
                    new_dp[g1][k] = (new_dp[g1][k] + ways) % MOD;
                    // 3. Add num into seq2
                    new_dp[j][g2] = (new_dp[j][g2] + ways) % MOD;
                }
            }
            dp = new_dp;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans = (ans + dp[i][i]) % MOD;
        }
        return ans;
    }
};
class Solution {
public:
    // int MaxStones(int M, int cur, vector<int>& suffix, vector<vector<int>>& memo)
    // {
    //     // Return max stones can take in piles[cur:] with M

    //     if (cur + 2 * M >= suffix.size() - 1) // Minus 1 because suffix size is n + 1.
    //         return suffix[cur];
    //     if (memo[cur][M] > 0) return memo[cur][M];
    //     // Current player play optimally, minimize the max stones opponent can take.
    //     int res = INT_MAX;
    //     for (int i = 0; i < 2 * M; i++)
    //         res = min(res, MaxStones(max(M, i + 1), cur + i + 1, suffix, memo)); 

    //     return memo[cur][M] = suffix[cur] - res; // All stones - opponent's maximum.
    // }
    // int stoneGameII(vector<int>& piles) {
    //     const int n = piles.size();
    //     vector<int> suffix(n + 1);
    //     suffix[n] = 0;
    //     for (int i = n - 1; i >= 0; i--)
    //         suffix[i] = suffix[i + 1] + piles[i];
    //     vector<vector<int>> memo(n, vector<int>(n));
        
    //     return MaxStones(1, 0, suffix, memo);
    // }
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector<int> suffix(n + 1);
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) // dp[n][n] because the beneath dp need the state of index n(no piles left).
            dp[i][n] = suffix[i];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = n; M >= 1; M--)
            {
                for (int j = 1; j <= 2 * M && i + j <= n; j++)
                {
                    dp[i][M] = max(dp[i][M], suffix[i] - dp[i + j][max(M, j)]); 
                }
            }
        }
        return dp[0][1];
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        // O(N^2)
        // vector<int> dp(n, INT_MAX);
        // dp[0] = 0;
        // for (int i = 0; i < n; i++)
        //     for (int j = 1; j <= nums[i] && (i + j) < n; j++)
        //         dp[i + j] = min(dp[i + j], dp[i] + 1);
        
        // return dp[n - 1];
        // O(N)
        int jumps = 0;
        int cur_end = 0; // Maximum reachable index on current jumps count.
        int farthest = 0; // Maximum reachable after jump.
        for (int i = 0; i < n; i++)
        {
            if (cur_end >= n - 1) return jumps;
            if (i > cur_end)
            {
                jumps++;
                cur_end = farthest;
            }
            farthest = max(farthest, i + nums[i]); 
        }
        return jumps;
    }
};
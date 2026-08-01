class Solution {
public:
    // bool dfs(int start, int end, int sum1, int sum2, vector<int>& nums, bool round)
    // {
    //     if (start > end)
    //     {
    //         if (sum1 >= sum2) return true;
    //         return false;
    //     }
    //     if (round)
    //     {
    //         if (dfs(start + 1, end, sum1 + nums[start], sum2, nums, !round) || dfs(start, end - 1, sum1 + nums[end], sum2, nums, !round))
    //             return true;
    //     }
    //     else
    //     {
    //         if (dfs(start + 1, end, sum1, sum2 + nums[start], nums, !round) && dfs(start, end - 1, sum1, sum2 + nums[end], nums, !round)) // && Because player 2 should play optimally.
    //             return true;
    //     }
    //     return false;
    // }
    // bool predictTheWinner(vector<int>& nums) {
    //     return dfs(0, nums.size() - 1, 0, 0, nums, 1);
    // }

    // Use Diff with memoization
    // int MaxDiff(vector<int>& nums, int left, int right, vector<vector<int>> &visited)
    // {
    //     if (visited[left][right] != -1) return visited[left][right];
    //     if (left == right) return visited[left][right] = nums[left];
    //     return visited[left][right] = max(nums[left] - MaxDiff(nums, left + 1, right, visited),
    //                                       nums[right] - MaxDiff(nums, left, right - 1, visited));
    // }

    // bool predictTheWinner(vector<int>& nums) {
    //     // Sum increase x when P1 choose, decrease x when P2 choose.
    //     vector<vector<int>> visited(nums.size(), vector<int> (nums.size(), -1));
    //     return MaxDiff(nums, 0, nums.size() - 1, visited) >= 0;
    // }

    bool predictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; j++)
            {   // Last max_diff[i + 1... j] store at dp[j]; max_diff[i + 1... j - 1] at dp[j - 1]
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]); // Update max_diff[i... j]
            }
        }
        return dp[n - 1] >= 0;
    }
};
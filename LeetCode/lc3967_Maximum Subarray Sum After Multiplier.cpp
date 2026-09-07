class Solution {
public:
    // long long op(long long num, int &k, bool flag)
    // {
    //     if (!flag) // multiplication
    //         return num * k;
    //     else
    //     {
    //         if (num >= 0)
    //             return num / k; // floor by default
    //         else
    //             return ceil(num / k);
    //     }
    // }
    // long long f(vector<int> &nums, int &k, bool flag)
    // {
    //     const int n = nums.size();
    //     // dp[i]: Maximum val at i index
    //     // dp1: Without transform (Standard Kadane)
    //     // dp2: With/without transform
    //     // dp3: After transform + Without transform (Or all transform)
    //     vector<long long> dp1(n), dp2(n), dp3(n); 
    //     dp1[0] = 1LL * nums[0]; dp2[0] = op(1LL * nums[0], k, flag); 
    //     dp3[0] = -1e11; // Non-empty array; therefore, no element when index 0
    //     long long mx = dp2[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         long long num = nums[i];
    //         long long val = op(1LL * num, k, flag);
    //         dp1[i] = max(dp1[i - 1] + num , num);
    //         dp2[i] = max({val, dp1[i - 1] + val, dp2[i - 1] + val});
    //         dp3[i] = max({dp2[i] , dp2[i - 1] + num, dp3[i - 1] + num});
    //         mx = max({mx, dp1[i], dp2[i], dp3[i]});
    //     }
    //     return mx;
    // }
    long long f(vector<int> &nums, int &k, bool flag)
    {
        const int n = nums.size();
        long long dp1, dp2, dp3; // Only need to record last step
        dp1 = nums[0];
        dp2 = (flag) ? (nums[0] / k) : (1LL * nums[0] * k);  // Default will handle ceil & floor
        dp3 = -1e11;
        long long mx = dp2;
        for (int i = 1; i < n; i++)
        {
            long long num = nums[i];
            long long val = (flag) ? (num / k) : (num * k);
            long long nx1 = max(dp1 + num, num);
            long long nx2 = max({val, dp1 + val, dp2 + val});
            long long nx3 = max({nx2, dp2 + num, dp3 + num});
            dp1 = nx1; dp2 = nx2; dp3 = nx3;
            mx = max(mx, max(dp2, dp3));
        }
        return mx;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(f(nums, k, 0), f(nums, k, 1));
    }
};
constexpr int MOD = 1000000007;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int n = nums.size();
        int idx_f = 0; 
        long long ans = 0;
        for (int i = 0; i < n; i++) // nums[i] < a pos
        {
            if (nums[i] < a)
            {
                ans = (ans + (i - idx_f)) % MOD;
                idx_f++;
            }
        }
        vector<int> nums2(n);
        int idx_s = idx_f;
        for (int i = 0; i < n; i++) // Arrange the array to (< a) | (>= a)
        {
            if (a <= nums[i]) 
            {
                nums2[idx_s++] = nums[i];
            }
        }
        for (int i = idx_f; i < n; i++) 
        {
            if (a <= nums2[i] && nums2[i] <= b)
            {
                ans = (ans + (i - idx_f)) % MOD;
                idx_f++;
            }
        }
        return (int) ans;
    }
};
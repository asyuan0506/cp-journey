class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int n = nums.size();
        int mx = 0; // 1 <= nums[i] <= 10^9
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            nums[i] = gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        long long sum = 0;
        while (left < right) {
            sum += gcd(nums[left++], nums[right--]);
        }
        return sum;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k % n;
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        auto my_reverse = [&nums](int left, int right) {
            right--; // Excluded
            while (left < right)
                swap(nums[left++], nums[right--]);
        };
        my_reverse(0, n);
        my_reverse(0, k);
        my_reverse(k, n);
    }
};
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> digit_range(nums.size(), 0);
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int largest = -1;
            int smallest = 10;
            while (num > 0)
            {
                int dig = num % 10;
                num /= 10;
                largest = max(largest, dig);
                smallest = min(smallest, dig);
            }
            digit_range[i] = largest - smallest;
            mx = max(mx, digit_range[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            {
                if (mx == digit_range[i])
                    ans += nums[i];
            }
        return ans;
    }
};
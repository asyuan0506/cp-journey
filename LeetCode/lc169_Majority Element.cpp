class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int cnt = 0;
        for (int num : nums)
        {
            if (cnt == 0)
                majority = num;
            cnt += num == majority ? 1 : -1;
        }
        return majority;
    }
};
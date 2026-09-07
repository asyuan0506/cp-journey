class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int cur = 1;
        for (int nxt = 2; nxt < nums.size(); nxt++)
        {
            if (nums[nxt] != nums[cur] || nums[nxt] != nums[cur - 1])
                nums[++cur] = nums[nxt];
        }
        return cur + 1;
    }
};
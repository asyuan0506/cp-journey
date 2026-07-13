class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums[0] - 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (last < 0) return false;
            nums[i] = max(last, nums[i]); // Greedy: Maximum jump
            last = nums[i] - 1;
        }
        return true;
    }
};
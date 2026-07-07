class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for (int nxt = 1; nxt < nums.size(); nxt++)
        {
            if (nums[nxt] != nums[cur]) // Keep finding different num
                nums[++cur] = nums[nxt]; // Put it to following element
        }
        return cur + 1; // cur is index
        
    }
};

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int nxt = 1;
        for (int i = 1; i < k; i++)
        {
            nxt = max(nxt, i);
            if (nums[i] <= nums[i - 1])
            {
                while (nxt < nums.size() && nums[i - 1] >= nums[nxt])
                {
                    k--;
                    nxt++;
                }
                if (nxt < nums.size())
                    swap(nums[i], nums[nxt++]);
            }
        }
        return k;
        
    }
};
*/
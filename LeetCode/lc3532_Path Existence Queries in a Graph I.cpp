class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int last = nums[0];
        int group = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - last > maxDiff) // nums is a sorted array, if > maxDiff -> new group of nodes
                group++;
            last = nums[i];
            nums[i] = group;       
        }
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0], right = queries[i][1];
            if (nums[left] == nums[right])
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
};
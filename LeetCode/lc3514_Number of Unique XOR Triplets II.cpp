class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> visited(2048, false); 
        // maximum value is 1500(11 bit -> 2048 possible numbers)
        vector<int> tmp(1, 0);
        visited[0] = true;

        const int n = nums.size();
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++) // if j == k res = 0
            {
                int res = nums[j] ^ nums[k];
                if (!visited[res])
                {
                    visited[res] = true;
                    tmp.push_back(res);
                }
            }
        }
        visited.assign(2048, false);
        int unique = 0;
        for (int num : nums)
        {
            for (int pre : tmp)
            {
                int res = num ^ pre;
                if (!visited[res])
                {
                    visited[res] = true;
                    unique++;
                }
            }
        }
        return unique;
    }
};
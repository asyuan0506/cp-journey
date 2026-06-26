// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         const int s = nums.size();
//         int ans = 0;
//         for (int i = 0; i < s; i++)
//         {
//             int cnt = 0;
//             for (int j = i; j < s; j++)
//             {
//                 int h = (j - i + 1) / 2;
//                 if (nums[j] == target)
//                     cnt++;
//                 if (cnt > h) 
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    int max_idx;
    vector<long long> bit; // Binary Indexed Tree
    void update(int v)
    {
        for (int i = v + 1; i <= max_idx; i += (i & (-i)))
            bit[i]++;
    }
    
    long long query(int v)
    {
        long long sum = 0;
        for (int i = v + 1; i > 0; i -= (i &(-i)))
            sum += bit[i];
        return sum;
    }

public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        max_idx = 2 * n + 1;  // [0, 2n]
        bit.assign(max_idx + 1, 0); // 1-indexed
        
        long long ans = 0;
        long long prefix = n;
        update(prefix);        
        for (int num : nums)
        {
            prefix += (num == target) ? 1 : -1;
            ans += query(prefix - 1);
            update(prefix);
        }
        return (int)ans;
    }
};
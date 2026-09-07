class Solution {
public:
    int max_idx;
    vector<int> bit;
    void update(int v)
    {
        if (v == 0) // Or use offset to avoid, but not intuitive
            return;
        for (int i = v; i <= max_idx; i += (i &(-i)))
            bit[i]++;
    }
    int query(int v)
    {
        int sum = 0;
        for (int i = v; i > 0; i -= (i & (-i)))
            sum += bit[i];
        return sum;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        // (nums[i] == target) ? 1 : -1
        // pre[b] - pre[a] > 0 -> pre[b] > pre[a] while b > a
        max_idx = 2 * n ;
        bit.assign(max_idx + 1, 0);
        int presum = n;
        update(presum);
        long long ans = 0;
        for (int num : nums)
        {
            presum += (num == target) ? 1 : -1;
            ans += query(presum - 1);
            update(presum);
        }
        return ans;
    }
};
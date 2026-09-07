class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        const int n = nums.size();
        vector<long long> pre(n + 1);
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long moved = pre[i];
            long long left = pre[n] - moved;
            long long sum[2] = { 0, 0 };
            if (i > n / 2)
            {
                long long left_ele = i - n / 2;
                sum[0] += pre[left_ele];
                sum[1] = moved - pre[left_ele];
                sum[0] += pre[n] - moved;
            }
            else
            {
                long long last = n / 2 - i;
                sum[1] += pre[n] - pre[n - last];
                sum[1] += pre[i];
                sum[0] = pre[n] - sum[1];
            }
            if (sum[0] > sum[1])
                ans++;
        }
        return ans;
    }
};
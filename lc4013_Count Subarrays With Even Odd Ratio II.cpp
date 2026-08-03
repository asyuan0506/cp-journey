class Solution
{
public:
    vector<long long> BIT;
    long long Query(int x)
    {
        long long sum = 0;
        for (; x < BIT.size(); x += x & (-x))
            sum += BIT[x];
        return sum;
    }
    void Update(int x)
    {
        for (; x >= 1; x -= x & (-x))
            BIT[x]++;
    }
    long long countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        const int n = nums.size();
        long long ans = 0;
        vector<long long> pre_x(n + 1, 0);
        vector<long long> pre_y(n + 1, 0);
        vector<long long> diff(n + 1);
        diff[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre_x[i] = pre_x[i - 1] + (nums[i - 1] % 2 == 0) * b;
            pre_y[i] = pre_y[i - 1] + (nums[i - 1] % 2) * a;
            // for (int j = 0; j <= i; j++)
            // {
            //     int x = pre_x[i] - pre_x[j];
            //     int y = pre_y[i] - pre_y[j];
            //     // x <= y -> x - y <= 0 -> pre_x[i] - pre_x[j] - pre_y[i] + pre_y[j] <= 0
            //     // pre_x[i] - pre_y[i] <= pre_x[j] - pre_y[j]    j <= i
            //     // For every i, count how many >= pre_x[i] - pre_y[i] -> BIT?
            //     if (y)
            //         ans += x <= y;     // ans += x * b <= a * y;
            // }
            diff[i] = pre_x[i] - pre_y[i];
        }
        vector<long long> sorted = diff;
        sort(sorted.begin(), sorted.end());
        BIT.assign(sorted.size() + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            int idx = lower_bound(sorted.begin(), sorted.end(), diff[i]) - sorted.begin() + 1;
            ans += Query(idx);
            Update(idx);
        }

        return ans;
    }
};
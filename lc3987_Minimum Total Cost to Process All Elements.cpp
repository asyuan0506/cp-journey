constexpr int MOD = 1000000007;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0;
        for (int num : nums)
            sum += num;
        sum -= k;
        long long quotient = sum / k + (sum % k > 0);
        long long ans;
        if ((1 + quotient) % 2 == 0)
        {
            ans = (((1 + quotient) / 2) % MOD) * (quotient % MOD) % MOD;
        }
        else
            ans = ((quotient / 2) % MOD) * ((1 + quotient) % MOD) % MOD;
        ans %= MOD;
        return (int) ans;
    }
};
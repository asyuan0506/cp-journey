class Solution {
public:
    static constexpr int MOD = 1000000007;
    static constexpr int MAX = 100001;
    inline static int pow[MAX]; // precompute all possible 10^n % MOD
    
    inline static int init = []() {
        pow[0] = 1;
        for (int i = 1; i < MAX; i++)
            pow[i] = pow[i - 1] * 10LL % MOD;
        return 1;
    }();

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int n = s.length();
        vector<int> pre_sum(n + 1, 0);
        vector<int> pre_val(n + 1, 0);
        vector<int> ln(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int d = s[i] - '0';
            pre_sum[i + 1] = pre_sum[i] + d;
            if (d != 0)
            {
                pre_val[i + 1] = (pre_val[i] * 10LL + d) % MOD;
                ln[i + 1] = ln[i] + 1;
            }
            else
            {
                pre_val[i + 1] = pre_val[i];
                ln[i + 1] = ln[i];
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0], right = queries[i][1];
            int sum = pre_sum[right + 1] - pre_sum[left];
            long long sub = pre_val[left] * 1LL * pow[ln[right + 1] - ln[left]] % MOD;
            long long x = (pre_val[right + 1] - sub + MOD) % MOD; // Prevent negative number
            ans[i] = x * sum % MOD;
        }
        return ans;
    }
};
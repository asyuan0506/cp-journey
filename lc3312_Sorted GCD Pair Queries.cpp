class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int m = *max_element(nums.begin(), nums.end());
        vector<int> counting(m + 1, 0);
        // vector<int> pairs(m + 1, 0);
        vector<long long> gcd_equal_i(m + 1, 0);
        for (int& num : nums)
            counting[num]++;
        for (int i = m; i >= 1; i--)
        {
            long long sum = counting[i];
            for (int j = 2 * i; j <= m; j += i)
            {
                sum += counting[j];
                gcd_equal_i[i] -= gcd_equal_i[j]; // Subtract gcd equal j elements
            }
            // pairs[i] = sum * (sum - 1) / 2;
            // gcd_equal_i[i] += pairs[i];
            gcd_equal_i[i] += sum * (sum - 1) / 2;
        }
        for (int i = 1; i <= m; i++)
            gcd_equal_i[i] += gcd_equal_i[i - 1]; // Prefix sum of elements that gcd equal i

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
            ans[i] = upper_bound(gcd_equal_i.begin(), gcd_equal_i.end(), queries[i]) - gcd_equal_i.begin();
        
        return ans;
    }
};
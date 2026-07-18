class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
                return s;
        if (n <= 3)
                return s + m;
        long long tmp_n = n / 2;
        long long tmp_m = m - 1;
        long long mx = s + 1LL * (tmp_n) * 1LL * tmp_m + 1;
        return mx;
    }
};
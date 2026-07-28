constexpr int MOD = 1000000007;
constexpr int maxN = 500001;
vector<long long> factorial;
class Solution {
public:
    inline static int init = []()
    {
        factorial.resize(maxN);
        factorial[0] = 1;
        for (int i = 1; i < maxN; i++)
            factorial[i] = factorial[i - 1] * i % MOD;
        return 0;
    }();
    long long fast_ex(long long base, int ex)
    {
        int res = 1;
        while (ex)
        {
            if (ex & 1)
                res = res * base % MOD;
            base = base * base % MOD; 
            ex >>= 1;
        }
        return res;
    }
    long long C(int n, int k)
    {
        // n! / (k! * (n - k)!) mod MOD
        // n! * k!^-1 * (n - k)!^-1 mod MOD
        // If GCD(a, m) == 1 -> a^(m - 1) % m = 1
        // a * a^(m - 2) % m = 1
        // a^(m - 2) % m = a^-1
        return (factorial[n] * 
            fast_ex(factorial[k], MOD - 2) % MOD) * 
            fast_ex(factorial[n - k], MOD - 2) % MOD;
    }
    int countValidSequences(int n, int k) {
        long long count = C(n - 1, k - 1);
        // All possible way of POSITIVE INT add k times = n -> C(n - 1, k - 1)
        // Minus all odd number add k times
        // 2(x1 + x2 +... xk) + k = n
        // (x1 + x2 +... xk) = (n - k) / 2
        // -> All possible way of NON NEGATIVE INT add k times = (n - k) / 2
        // -> C((n - k) / 2 + k - 1, k - 1)
        long long odd_count;
        if ((n - k) % 2)
            odd_count = 0;
        else
            odd_count = C((n - k) / 2 + k - 1, k - 1);
        return (count - odd_count + MOD) % MOD;
    }
};
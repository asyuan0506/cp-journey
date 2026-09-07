class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tmp = t;
        for (int i = 9; i >= 2; i--)
        {
            while (tmp % i == 0)
                tmp /= i;
        }
        if (tmp > 1) return "-1";

        const int n = num.length();
        vector<long long> rem(n + 1);
        rem[0] = t;
        int pos = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == '0')
            {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }
        if (rem[n] == 1) return num;
        
        // Increase digit, check suffix
        for (int i = pos; i >= 0; i--)
        {
            while (++num[i] <= '9')
            {
                long long t_now = rem[i] / gcd(rem[i], num[i] - '0');
                int divisor = 9;
                for (int j = n - 1; j > i; j--)
                {
                    while (t_now % divisor != 0)
                        divisor--;
                    t_now /= divisor;
                    num[j] = divisor + '0';
                }
                if (t_now == 1)
                    return num;
            }
        }
        // No valid n-digit number >= num exists.
        // Build the smallest valid number with at least n + 1 digits.
        string ans;
        int divisor = 9;
        while (t > 1)
        {
            while (t % divisor != 0)
                divisor--;
            t /= divisor;
            ans += divisor + '0';
        }
        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
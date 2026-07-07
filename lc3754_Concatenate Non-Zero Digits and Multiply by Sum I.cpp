class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int mul = 1;
        int sum = 0;
        while (n > 0)
        {
            int tmp = n % 10;
            if (tmp)
            {
                x = tmp * mul + x;
                sum += tmp;
                mul *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};
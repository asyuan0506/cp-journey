class Solution
{
public:
    // int smallestNumber(int n, int t) {
    //     for (; n <= INT_MAX; n++)
    //     {
    //         int product = 1;
    //         for (int tmp = n; tmp >= 1; tmp /= 10)
    //         {
    //             product *= tmp % 10;
    //         }
    //         if (product % t == 0)
    //             return n;
    //     }
    //     return 0;
    // }

    int smallestNumber(int n, int t)
    {
        // n t
        // q = floor(n / 10), r = n % 10
        // q*x % t = 0
        // g = gcd(q, t)
        // q = ga, t = gb
        // ga * x  % gb = 0
        // ax % b = 0 because gcd(a, b) = 1
        // x % b = 0
        // b = t / gcd(q, t) -> x % (t / gcd(q, t)) = 0 && x >= r(Constraint: smallest num >= n)
        int q = n / 10, r = n % 10;
        int g = gcd(max(q, 1), t);
        int b = t / g;
        int x;
        if (r % b == 0)
            x = r;
        else
            x = (r / b + 1) * b;
        if (x < 10)
            return q * 10 + x;

        return (q + 1) * 10;
    }
};
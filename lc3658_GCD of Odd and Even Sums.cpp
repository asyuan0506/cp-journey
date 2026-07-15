class Solution {
public:
    int GCD(int a, int b) {
        while ((a %= b) && (b %= a));
        return a + b;
    }
    int gcdOfOddEvenSums(int n) {
        int last_odd = 1 + 2 * (n - 1);
        int sum_odd = (1 + last_odd) * n / 2;
        int sum_even = (2 + last_odd + 1) * n / 2;
        return GCD(sum_odd, sum_even);
    }
};
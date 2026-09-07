class Solution {
public:
    int maxProduct(int n) {
        // int mx1 = 0, mx2 = 0;
        // while (n >= 1)
        // {
        //     int digit = n % 10;
        //     n /= 10;
        //     if (digit >= mx1)
        //     {
        //         mx2 = mx1;
        //         mx1 = digit;
        //     }
        //     else if (digit > mx2)
        //         mx2 = digit;
        // }
        // return mx1 * mx2;   
        uint64_t m = 0;
        for (; n >= 1; n /= 10)
            m += 1ULL << (n % 10 << 2);
        
        int mx1 = (bit_width(m) - 1) >> 2;
        // int mx2 = (bit_width(m - (1ULL << (mx1 << 2))) - 1) >> 2;
        // return mx1 * mx2;
        return mx1 * ((bit_width(m - (1ULL << (mx1 << 2))) - 1) >> 2);
    }
};
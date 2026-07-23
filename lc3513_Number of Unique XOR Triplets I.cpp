class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // int mx = *max_element(nums.begin(), nums.end()); 
        int mx = nums.size(); // nums include [1, n], so the size is max_element.
        // XOR is commutative, so the order doesn't matter. 
        if (mx <= 2) return mx;
        // If mx >= 3, it can control every bit.
        int ans = 1;
        // while (mx / ans >= 1)
        //     ans *= 2;
        while (mx >= ans)
            ans <<= 1;

        return ans;
    }
};
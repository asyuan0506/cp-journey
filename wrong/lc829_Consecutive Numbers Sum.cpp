class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // TLE O(N^2)
        // deque<int> de;
        // int ans = 0;
        // int sum = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     while (sum + i > n)
        //     {
        //         sum -= de.front();
        //         de.pop_front();
        //     }
        //     de.push_back(i);
        //     sum += i;
        //     if (sum == n)
        //         ans++; 
        // }
        // return ans;

        int ans = 0;
        // (x + 0) + (x + 1) ... (x + k - 1) = N
        // kx + (k - 1)k / 2 = N
        // kx = N - (k - 1)k / 2
        // x = (N - (k - 1)k / 2) / k
        // x >= 1, (N - (k - 1)k / 2) >= k
        // N >= k + (k - 1)k / 2, (k - 1)k / 2 = 1 + 2 +...(k-1), 
        // N >= 1 + 2 +...k -> N >= (1 + k)k / 2 -> 2N >= k^2
        for (int k = 1; k <= sqrt(2 * n); k++)
        {
            if ((n - (k - 1) * k / 2) % k == 0)
                ans++;
        }
        
        return ans;
    }
};
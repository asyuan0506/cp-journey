// vector<long long> BIT;
// class Solution {
// public:
    
//     void Update(int x, int v)
//     {
//         for (; x < BIT.size(); x += x & (-x))
//             BIT[x] += v;
//     }
//     long long Query(int x)
//     {
//         long long sum = 0;
//         for (; x > 0; x -= x & (-x))
//             sum += BIT[x];
//         return sum;
//     }
//     long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
//         const int n = monsters.size();
//         BIT.assign(n + 1, 0);
//         for (vector<int>& boost : boosts)
//         {
//             int l = boost[0], r = boost[1], v = boost[2];
//             // Difference array
//             Update(l + 1, v); // BIT so index + 1 
//             Update(r + 2, -v);
//             // Actually, just use a diff array and calculate prefix sum one time.
//         }
//         long long strength = 0; 
//         for (int i = n - 1; i >= 0; i--)
//         {
//             long long boost = Query(i + 1);
//             cout << boost << "\n";
//             if (strength == 0 && boost - monsters[i] < 0)
//             {
//                 strength += monsters[i] - boost;
//             }
//             else if (strength > 0) // index after i need strength
//                 strength += monsters[i];
//         }
//         return strength;
//     }
// };

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        const int n = monsters.size();
        vector<long long> diff(n + 1, 0);
        for (vector<int>& boost : boosts)
        {
            int l = boost[0], r = boost[1], v = boost[2];
            diff[l] += v;
            diff[r + 1] -= v;
        }
        vector<long long> prefix(n); // Inclusive
        prefix[0] = diff[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + diff[i];
        }
        long long strength = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            long long boost = prefix[i];
            if (strength == 0 && boost - monsters[i] < 0)
            {
                strength += monsters[i] - boost;
            }
            else if (strength)
                strength += monsters[i];
        }
        return strength;
    }
};
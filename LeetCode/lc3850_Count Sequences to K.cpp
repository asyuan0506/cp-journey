// TLE
constexpr int offset1 = 38;
constexpr int offset2 = 19;
constexpr int offset3 = 19;

class Solution {
public:
    vector<int> GetPower(long long& num) {
        vector<int> value(3, 0);
        while (num % 2 == 0)
        {
            value[0]++;
            num /= 2;
        }
        while (num % 3 == 0)
        {
            value[1]++;
            num /= 3;
        }
        while (num % 5 == 0)
        {
            value[2]++;
            num /= 5;
        }
        return value;
    }
    static bool out (int& i, int& j, int& k) {
        return (i < 0 || j < 0 || k < 0 || i >= 77 || j >= 39 || k >= 39);
    }
    int countSequences(vector<int>& nums, long long k) {
        vector<int> value_k = GetPower(k);
        if (k != 1) return 0;
        int target1 = value_k[0] + offset1;
        int target2 = value_k[1] + offset2;
        int target3 = value_k[2] + offset3;
        if (out(target1, target2, target3)) return 0;

        vector<vector<vector<int>>> dp(77, vector<vector<int>>(39, vector<int> (39, 0))); // 4 ^ 19 = 2 ^ 38
        dp[offset1][offset2][offset3] = 1;
        for (int num : nums) {
            vector<vector<vector<int>>> new_dp(77, vector<vector<int>>(39, vector<int> (39, 0)));
            long long tmp = num;
            vector<int> value = GetPower(tmp);
            for (int i = 0; i < 77; i++)
            {
                int idx1[3] = { i + value[0], i - value[0], i};
                for (int j = 0; j < 39; j++)
                {
                    int idx2[3] = { j + value[1], j - value[1], j};
                    for (int k = 0; k < 39; k++)
                    {
                        int ways = dp[i][j][k];
                        if (ways == 0) continue;
                        int idx3[3] = { k + value[2], k - value[2], k};
                        for (int l = 0; l < 3; l++)
                        {
                            if (!out(idx1[l], idx2[l], idx3[l]))
                                new_dp[idx1[l]][idx2[l]][idx3[l]] += ways;
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        
        return dp[target1][target2][target3];
    }
};
// -----------------------------------
class Solution {
public:
    unordered_map<string, int> visited;
    int dfs(vector<int>& nums, long long& k, int i, int p2, int p3, int p5)
    {
        if (i >= nums.size())
        {
            if ((p2 >= 0 && p3 >= 0 && p5 >= 0) && (pow(2, p2) * pow(3, p3) * pow(5, p5) == k))
                return 1;
            return 0;
        }
        string stat = to_string(i) + '#' + to_string(p2) + '#' + to_string(p3) + '#' + to_string(p5);
        if (visited.find(stat) != visited.end())
            return visited[stat];
        
        int tp2 = (nums[i] == 4) ? 1 : 0, tp3 = 0, tp5 = (nums[i] == 5) ? 1 : 0;
        if (nums[i] % 2 == 0) tp2++;
        if (nums[i] % 3 == 0) tp3++;
        int ans = 0;
        ans += dfs(nums, k, i + 1, p2, p3, p5); // skip
        ans += dfs(nums, k, i + 1, p2 + tp2, p3 + tp3, p5 + tp5); // Multiply
        ans += dfs(nums, k, i + 1, p2 - tp2, p3 - tp3, p5 - tp5); // Divide
        visited[stat] = ans;
        return ans; 
    }
    int countSequences(vector<int>& nums, long long k) {
        return dfs(nums, k, 0, 0, 0, 0);
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 10000000);  // bigger than 1000 * 1000
        dp[0] = cost[0]; dp[1] = cost[1];   // represent what this stair will cost
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[cost.size() - 2], dp[cost.size() - 1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0); // Append 0 for the top step [10, 15, 20, 0]

        for (int i = n - 3; i >= 0; i--) {                    
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }

        return min(cost[0], cost[1]);        
    }
};

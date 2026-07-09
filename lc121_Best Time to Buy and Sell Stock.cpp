class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = INT_MAX;
        int profit = INT_MIN;
        for (int price : prices)
        {
            cur_min = min(cur_min, price);
            profit = max(profit, price - cur_min);
        }
        return profit;
    }
};
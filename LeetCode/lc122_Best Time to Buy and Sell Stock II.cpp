class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // int cur_min = INT_MAX;
        // for (int price : prices)
        // {
        //     if (price > cur_min)  // Sell whenever price higher
        //     {
        //         profit += price - cur_min;
        //         cur_min = price;
        //     }
        //     else
        //         cur_min = price;
        // }
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
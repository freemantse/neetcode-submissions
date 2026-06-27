class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int profit = 0;
        for (const int& price : prices) {
            profit = max(profit, price - min_buy);
            min_buy = min(min_buy,price);
        }
        return profit;
    }
};

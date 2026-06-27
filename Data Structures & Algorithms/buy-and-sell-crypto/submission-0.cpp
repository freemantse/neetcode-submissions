class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        for (int r  = 0; r < prices.size(); r++) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            profit = max(profit, prices[r] - prices[l]);
        }
        return profit;
    }
};

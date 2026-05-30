class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, sell = 1;
        int profit = 0;
        while(sell < n) {
            if(prices[buy] >= prices[sell]) {
                buy = sell;
            }
            else {
                profit = max(profit,prices[sell] - prices[buy]);
            }
            sell++;
        }
        return profit;
    }
};
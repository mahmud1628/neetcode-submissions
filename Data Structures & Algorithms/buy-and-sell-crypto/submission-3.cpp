class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buying_price_so_far = prices[0];
        for(int i : prices) {
            min_buying_price_so_far = min(min_buying_price_so_far, i);
            max_profit = max(max_profit, i - min_buying_price_so_far);
        }
        
        return max_profit;
    }
};

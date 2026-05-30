class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int left = 0, right  = 1;
        int n = prices.size();
        int max_profit = 0;
        
        while(left < n && right < n) {
            max_profit = max(max_profit, prices[right] - prices[left]);
            if(prices[left] <= prices[right]) right++;
            else left++;
        }

        return max_profit;
    }
};

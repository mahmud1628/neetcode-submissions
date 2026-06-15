class Solution {
    void searchCombinations(vector<int> & coins, int amount, int index, int  current_coins, int & min_coins) {
        if(amount == 0) {
            min_coins = min(min_coins, current_coins);
            return;
        }
        if(amount < 0 || index >= coins.size()) return;

        // pick current coin
        searchCombinations(coins, amount - coins[index], index, current_coins + 1, min_coins);

        // don't pick current coin
        searchCombinations(coins, amount, index + 1, current_coins, min_coins);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int min_coins = INT_MAX;
        searchCombinations(coins, amount, 0, 0, min_coins);
        if(min_coins == INT_MAX) return -1;
        return min_coins;
    }
};

class Solution {
    int searchCombinations(vector<int> & coins, int amount, int index, vector<vector<int>> & mem) {
        if(amount < 0 || index >= coins.size()) return -1;
        if(amount == 0) return mem[index][amount] = 0;
        if(mem[index][amount] == -1) {

            // pick current coin
            int a = -1;
            int r = searchCombinations(coins, amount - coins[index], index, mem);
            if(r != -1) a = 1 + r;
            // don't pick current coin
            int b = searchCombinations(coins, amount, index + 1, mem);
            int t;
            if(a == -1) t = b;
            else if(b == -1) t = a;
            else t = min(a, b);
            mem[index][amount] = t;
        }

        return mem[index][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> mem(coins.size(), vector<int>(amount + 1, -1));
        return searchCombinations(coins, amount, 0, mem);
    }
};

class Solution {
    int rob(vector<int> & nums, vector<int> & money, int index) {
        if(index >= nums.size()) return 0;
        if(money[index] == -1) {
            int rob_current = nums[index] + rob(nums, money, index + 2);
            int rob_next = rob(nums, money, index + 1);
            money[index] = max(rob_current, rob_next);
        }

        return money[index];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size(), -1);
        return rob(nums, money, 0);
    }
};

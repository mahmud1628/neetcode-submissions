class Solution {
    int rob(vector<int> & nums, vector<int> & money, int index, int limit) {
        if(index > limit) return 0;
        if(money[index] == -1) {
            int rob_current = nums[index] + rob(nums, money, index + 2, limit);
            int rob_next = rob(nums, money, index + 1, limit);
            money[index] = max(rob_current, rob_next);
        }

        return money[index];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> money0(nums.size(), -1);
        vector<int> money1 = money0;
        return max(rob(nums, money0, 0, nums.size() - 2), rob(nums, money1, 1, nums.size() - 1));
    }
};

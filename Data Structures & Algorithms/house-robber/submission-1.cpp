class Solution {
    int helper(int house, vector<int> & nums, vector<int> & mem) {
        if(house >= nums.size()) return 0;
        if(mem[house] == -1)
            mem[house] = max(nums[house] + helper(house + 2, nums, mem), helper(house + 1, nums, mem));
        return mem[house];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> mem(nums.size(), -1);
        return helper(0, nums, mem);
    }
};

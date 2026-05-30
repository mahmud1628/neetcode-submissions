class Solution {
    int helper(int house, vector<int> & nums, vector<int> & mem, int limit) {
        if(house > limit) return 0;
        if(mem[house] == -1)
            mem[house] = max(nums[house] + helper(house + 2, nums, mem, limit), helper(house + 1, nums, mem, limit));
        return mem[house];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> mem1(nums.size(), -1);
        vector<int> mem2 = mem1;
        return max(helper(0, nums, mem1, nums.size() - 2), helper(1, nums, mem2, nums.size() - 1));
    }
};

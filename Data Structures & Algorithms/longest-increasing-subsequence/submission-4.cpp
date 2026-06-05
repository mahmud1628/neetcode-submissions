class Solution {
    int LIS(vector<int> & nums, int index, int prev_index, vector<vector<int>> & mem) {
        if(index >= nums.size()) return 0;
        if(mem[index + 1][prev_index + 1] == -1) {
            int a, b = -1;
            a = LIS(nums, index + 1, prev_index, mem);
            if(prev_index == -1 || nums[index] > nums[prev_index]) b = 1 + LIS(nums, index + 1, index, mem);
            mem[index + 1][prev_index + 1] = max(a, b);
        }
        return mem[index + 1][prev_index + 1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> mem(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return LIS(nums, 0, -1, mem);
    }
};

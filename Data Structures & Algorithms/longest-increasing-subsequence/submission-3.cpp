class Solution {
    int recursiveLIS(int index, int prev_index, vector<int> & nums, vector<vector<int>> & mem) {
        if(index == nums.size()) return 0;
        if(mem[index + 1][prev_index + 1] != -1) return mem[index + 1][prev_index + 1];
        int len = recursiveLIS(index + 1, prev_index, nums, mem);
        if(prev_index == -1 || nums[index] > nums[prev_index]) len = max(len, 1 + recursiveLIS(index + 1, index, nums, mem));
        return mem[index + 1][prev_index + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> mem(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        return recursiveLIS(0, -1, nums, mem);
    }
};

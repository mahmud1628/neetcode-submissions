class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest_reach = 0;
        int target = nums.size() - 1;

        for(int i = 0; i <= farthest_reach; i++) {
            farthest_reach = max(farthest_reach, i + nums[i]);
            if(farthest_reach >= target) return true;
        }

        return false;
    }
};

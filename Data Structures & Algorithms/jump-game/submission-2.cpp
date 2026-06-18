class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest_reach = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > farthest_reach) return false;
            if(farthest_reach >= nums.size() - 1) return true;
            if(farthest_reach < i + nums[i]) farthest_reach = i + nums[i];
        }

        return farthest_reach >= nums.size() - 1;
    }
};

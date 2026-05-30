class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int prev1 = nums[0], prev2 = max(nums[0], nums[1]), maximum;
        for(int i=2;i<nums.size();i++){
           maximum = max(prev1 + nums[i], prev2);
           prev1 = prev2;
           prev2 = maximum;
        }
        return maximum;
    }
};
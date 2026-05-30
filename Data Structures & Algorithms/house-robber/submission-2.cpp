class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size());
        if(nums.size()==1) return nums[0];
        money[0] = nums[0];
        money[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            money[i] = max(money[i-1],money[i-2]+nums[i]);
        }
        return money[nums.size()-1];
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int s = nums[0];
        int max_sum = s;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < 0 && s < 0) {
                s = 0;
            }
            s += nums[i];

            max_sum = max(max_sum, s);
        }

        return max_sum;
    }
};

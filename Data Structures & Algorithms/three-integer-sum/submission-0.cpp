class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i<nums.size();i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            int pre1 = nums[0] - 1;
            int pre2 = pre1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    if(left <= i) {
                        left++;
                        continue;
                    }
                    if(pre1 == nums[left] && pre2 == nums[right]) {
                        left++;
                        right--;
                        continue;
                    }
                    res.push_back({nums[i],nums[left],nums[right]});
                    pre1 = nums[left];
                    pre2 = nums[right];
                    left++;
                    right--;
                }
                else if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }

            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            int prev_first = nums[0] - 1;
            int prev_second = prev_first;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    if(nums[left] == prev_first && nums[right] == prev_second) {
                        left++;
                        right--;
                        continue;
                    }
                    result.push_back({nums[i], nums[left], nums[right]});
                    prev_first = nums[left];
                    prev_second = nums[right];
                    left++;
                    right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }

        return result;
    }
};

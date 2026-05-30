class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(left == right - 1 || left == right) {
                return min(nums[left],nums[right]);
            }
            if(nums[mid] > nums[left] && nums[right] < nums[mid]) {
                left = mid + 1;
            }
            else if(nums[mid] < nums[left] && nums[mid] < nums[mid - 1]) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            if(left == right) return nums[left];
            if(left == right - 1) return min(nums[left], nums[right]);

            int mid = left + (right - left) / 2;

            if(nums[left] < nums[mid] && nums[mid] < nums[right]) right = mid;

            else if(nums[left] > nums[mid] && nums[mid] < nums[right]) right = mid;

            else if(nums[left] < nums[mid] && nums[mid] > nums[right]) left = mid;
        }

        return -1;
    }
};

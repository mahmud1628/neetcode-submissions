class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;

            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            if(nums[left] < nums[mid]) { // left half including mid is sorted
                if(nums[left] < target && target < nums[mid]) right = mid - 1; // check whether in that sorted portion or not
                else left = mid + 1;
            } else { // right half including mid is sorted
                if(nums[mid] < target && target < nums[right]) left = mid + 1; // check whether in that sorted portion or not
                else right = mid - 1;
            }
        }

        return -1;
    }
};

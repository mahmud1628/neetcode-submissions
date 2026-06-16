class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;

        int prefix_product = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                max_product = max(max_product, 0);
                prefix_product = 1;
            } else {
                prefix_product = prefix_product * nums[i];
                max_product = max(max_product, prefix_product);
            }
        }

        int suffix_product = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                max_product = max(max_product, 0);
                suffix_product = 1;
            } else {
                suffix_product = suffix_product * nums[i];
                max_product = max(max_product, suffix_product);
            }
        }

        return max_product;
    }
};

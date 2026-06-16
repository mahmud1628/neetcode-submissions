class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int n = nums.size();

        int prefix_product = 1;
        int suffix_product = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                max_product = max(max_product, 0);
                prefix_product = 1;
            } else {
                prefix_product = prefix_product * nums[i];
                max_product = max(max_product, prefix_product);
            }

            if(nums[n - i - 1] == 0) {
                max_product = max(max_product, 0);
                suffix_product = 1;
            } else {
                suffix_product = suffix_product * nums[n - i - 1];
                max_product = max(max_product, suffix_product);
            }
        }

        return max_product;
    }
};

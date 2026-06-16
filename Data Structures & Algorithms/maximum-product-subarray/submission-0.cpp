class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            int current_product = 1;
            for(int j = i; j < nums.size(); j++) {
                current_product *= nums[j];
                max_product = max(max_product, current_product);
            }
        }

        return max_product;
    }
};

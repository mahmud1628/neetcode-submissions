class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_products(nums.size(), 1);
        vector<int> suffix_products(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++) {
            prefix_products[i] = prefix_products[i-1] * nums[i-1];
        }

        for(int i = nums.size() - 2; i >= 0; i--) {
            suffix_products[i] = suffix_products[i+1] * nums[i+1];
        }

        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            res.push_back(prefix_products[i] * suffix_products[i]);
        }

        return res;
    }
};

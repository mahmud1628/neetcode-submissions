class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];
        int running_max = max_product;
        int running_min = max_product;

        for(int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            int a = running_max * n;
            int b = running_min * n;
            running_max = max(max(a, b), n);
            running_min = min(min(a, b), n);

            max_product = max(max_product, running_max);
        }

        return max_product;
    }
};

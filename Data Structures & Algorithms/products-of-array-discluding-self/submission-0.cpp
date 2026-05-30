class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int t = 1;
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = t;
            t = t * nums[i];
        }
        t = 1;
        for(int i = n-1;i>=0;i--) {
            ans[i] *= t;
            t = t * nums[i];
        }
        return ans;
    }
};
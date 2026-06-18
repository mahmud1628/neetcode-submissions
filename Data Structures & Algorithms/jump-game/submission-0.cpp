class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n, false); // ith value indicates whether we can go from index i to the end
        v[n - 1] = true;

        for(int i = n - 2; i >= 0; i--) {
            int max_jump_len = nums[i];

            for(int jump_len = max_jump_len; jump_len > 0; jump_len--) {
                if(i + jump_len < n && v[i + jump_len]) {
                    v[i] = true;
                    break;
                }
            }
        }

        return v[0];
    }
};

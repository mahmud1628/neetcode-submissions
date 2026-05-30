class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto a : nums) 
            s.insert(a);
        int ans = 0;
        for(int i = 0;i<nums.size();i++ ) {
            if(s.find(nums[i] - 1) == s.end()) {
                int temp = nums[i];
                int temp_ans = 0;
                while(s.find(temp++) != s.end()) {
                    temp_ans++;
                }
                ans = ans > temp_ans ? ans : temp_ans;
            }
        }
        return ans;
    }
};
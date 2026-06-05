class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int zor = 0;
        for(int i = 0; i < nums.size(); i++) {
            zor = zor ^ nums[i];
        }
        int max = nums.size();
        for(int i = 0; i<= max; i++) zor = zor ^ i;
        return zor;
    }
};

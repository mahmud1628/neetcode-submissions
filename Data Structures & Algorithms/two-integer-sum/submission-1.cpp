class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            int n = target - nums[i];
            if(m.find(n) == m.end()) m[nums[i]] = i;
            else return {m[n],i};
        }
        return {-1,-1};
    }
};

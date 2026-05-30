class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_of_all = n * (n + 1) / 2;
        int sum_of_array = 0;
        for(int i : nums) sum_of_array += i;
        return sum_of_all - sum_of_array;
    }
};

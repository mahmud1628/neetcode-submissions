class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int i : nums) m.insert(i);

        int length = 0;

        for(int i : nums) {
            if(m.find(i - 1) == m.end()) { // so i is the smallest member of a sequence
                int curr_length = 1;
                int curr = i;
                while(m.find(curr + 1) != m.end()) { // find the bigger members sequentially for that sequence
                    curr_length++;
                    curr++;
                }

                length = max(length, curr_length);
            }
        }

        return length;
    }
};

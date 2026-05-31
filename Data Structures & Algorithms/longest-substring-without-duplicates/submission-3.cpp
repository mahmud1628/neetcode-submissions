class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int max_length = 0;
        int start = 0; 
        int end = 1;
        unordered_map<char, int> m;
        m[s[start]] = start;
        int n = s.size();
        int curr_length = 1;

        while(end < n) {
            if(m.find(s[end]) == m.end()) curr_length++;
            else {
                max_length = max(max_length, curr_length);
                start = max(m[s[end]] + 1, start);
                curr_length = end - start + 1;
            }

            m[s[end]] = end;

            end++;
        }

        max_length = max(max_length, curr_length);

        return max_length;
    }
};

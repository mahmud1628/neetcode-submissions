class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        unordered_map<char,int> m;
        int start = -1;
        int max_length = 0;
        int i;
        for(i = 0;i < s.size();i++) {
            if(m.find(s[i]) != m.end() && m[s[i]] > start) {
                start = m[s[i]];
            }
            m[s[i]] = i;
            max_length = max(max_length,i - start);
        }
        return max_length;
    }
};
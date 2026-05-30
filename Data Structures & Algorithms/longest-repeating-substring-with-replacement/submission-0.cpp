class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,right = 1;
        int max_length = 0;
        int max_frequency = 1;
        unordered_map<char,int> m;
        m[s[left]] = 1;
        while(right < s.size()) {
            if(m.find(s[right]) == m.end()) {
                m[s[right]] = 1;
            }
            else {
                m[s[right]]++;
                if(m[s[right]] > max_frequency) {
                    max_frequency = m[s[right]];
                }
            }
            if(right - left + 1 - max_frequency <= k) {
                max_length = max(max_length,right - left + 1);
            }
            else {
                m[s[left]] = m[s[left]] - 1;
                left++;
            }
            right++;
        }
        return max_length;
    }
};

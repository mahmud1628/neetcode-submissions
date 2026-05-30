class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() <= 1) return s.size();
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
            if(right - left + 1 - max_frequency > k) {
                max_length = max(max_length,right - left);
                m[s[left]]--;
                left++;
            }
            right++;
        }
        return max(max_length,right - left);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = 0;
        unordered_set<string> words;
        for(string word : wordDict) {
            words.insert(word);
            if(max_len < word.size())
                max_len = word.size();
        }
        vector<int> valid(s.size() + 1, false); // valid[i] denotes whether the prefix s[0...i-1] can be segmented or not
        valid[0] = true; // empty string is valid

        for(int i = 1; i < valid.size(); i++) {
            for(int len = 1; len <= max_len && len <= i; len++) {
                int j = i - len;
                if(valid[j] && words.find(s.substr(j, len)) != words.end()) {
                    valid[i] = true;
                    break;
                }
            }
        }

        return valid[valid.size() - 1];
    }
};

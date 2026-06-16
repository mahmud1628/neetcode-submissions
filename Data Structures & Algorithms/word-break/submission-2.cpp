class Solution {
    bool wordBreak(string & s, int start, unordered_set<string> & words, vector<int> & visited, int & max_len) {
        if(start == s.size()) return true;
        if(visited[start] != -1) return visited[start];

        string prefix = "";
        for(int i = start; i < s.size() && (i - start + 1) <= max_len; i++) {
            prefix += s[i];
            if(words.find(prefix) != words.end()) {
                if(wordBreak(s, i + 1, words, visited, max_len)) {
                    return visited[start] = 1;
                }
            }
        }
        return visited[start] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = 0;
        unordered_set<string> words;
        for(string word : wordDict) {
            words.insert(word);
            if(max_len < word.size())
                max_len = word.size();
        }
        vector<int> visited(s.size(), -1); // -1 unvisited, 1 true, 0 false

        return wordBreak(s, 0, words, visited, max_len);
    }
};

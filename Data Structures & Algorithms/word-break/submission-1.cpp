class Solution {
    bool wordBreak(string & s, int start, unordered_set<string> & words, vector<int> & visited) {
        if(start == s.size()) return true;
        if(visited[start] != -1) return visited[start];

        string prefix = "";
        for(int i = start; i < s.size(); i++) {
            prefix += s[i];
            if(words.find(prefix) != words.end()) {
                if(wordBreak(s, i + 1, words, visited)) {
                    return visited[start] = 1;
                }
            }
        }
        return visited[start] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(string word : wordDict) words.insert(word);
        vector<int> visited(s.size(), -1); // -1 unvisited, 1 true, 0 false

        return wordBreak(s, 0, words, visited);
    }
};

class Solution {
    map<char, int> getCharMap(string &s) {
        map<char, int> m;
        for(char c : s) {
            m[c]++;
        }
        return m;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> m;

        for(string s : strs) {
            map<char, int> charMap = getCharMap(s);
            m[charMap].push_back(s);
        }

        vector<vector<string>> res;

        for(auto i : m) {
            res.push_back(i.second);
        }

        return res;
    }
};

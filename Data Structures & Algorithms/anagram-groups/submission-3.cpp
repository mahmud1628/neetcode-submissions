class Solution {
    string getHashKey(string s) {
        vector<int> v(26, 0);
        for(char c: s) v[c - 'a']++;
        string key = "";
        for(auto i : v) key += "-" + to_string(i);
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s : strs) {
            string key = getHashKey(s);
            m[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto i : m) {
            res.push_back(i.second);
        }

        return res;
    }
};

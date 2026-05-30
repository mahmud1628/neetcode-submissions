class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        for(string s : strs) {
            vector<int> a(26,0);
            for(auto ch : s)  {
                a[ch - 'a']++;
            }
            if(m.find(a) == m.end()) {
                m[a] = {};
                m[a].push_back(s);
            }
            else {
                m[a].push_back(s);
            }
        }
        map<vector<int>,vector<string>> :: iterator it ;
        it = m.begin();
        vector<vector<string>> res;
        while(it!= m.end()) {
            res.push_back(it->second);
            it++;
        }
        return res;

    }
};
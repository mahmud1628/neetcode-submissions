class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> u_map;
        vector<vector<string>> res;
        int index = 0;
        for(auto s : strs) {
            string t = s;
            sort(t.begin(),t.end());
            if(u_map.find(t) == u_map.end()) {
                u_map[t] = index;
                res.push_back({});
                res[index].push_back(s);
                index++;
            }
            else {
                res[u_map[t]].push_back(s);
            }
        }
        return res;
    }
};
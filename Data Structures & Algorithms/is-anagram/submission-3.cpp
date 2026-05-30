class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> cnt;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == t[i]) continue;
            cnt[s[i]]++;
            cnt[t[i]]--;
        }

        for(auto p : cnt) {
            if(p.second !=0 ) return false;
        }

        return true;
    }
};

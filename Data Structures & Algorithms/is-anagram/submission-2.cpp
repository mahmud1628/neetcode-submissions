class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        else {
            unordered_map<char,int> m;
            m[s[0]] = 1;
            for(int i=1;i<s.size();i++) {
                if(m.find(s[i]) == m.end()) m[s[i]] = 1;
                else m[s[i]]++;
            }
            for(int i=0;i<t.size();i++) {
                if(m.find(t[i]) == m.end()) return false;
                else {
                    m[t[i]]--;
                    if(m[t[i]] == 0) m.erase(t[i]);
                }
            }
            return m.empty();
        }
        return true;
    }
};
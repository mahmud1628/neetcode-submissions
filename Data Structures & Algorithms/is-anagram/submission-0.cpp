class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        else {
            map<char,int> m;
            for(int i=0;i<s.size();i++) {
                if(m.empty()) m[s[i]] = 1;
                else if(m.find(s[i]) == m.end()) m[s[i]] = 1;
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

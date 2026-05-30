class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<s.size();i++)
            a[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            b[t[i]-'a']++;
        for(int i=0;i<t.size();i++)
                if(a[t[i]-'a']!=b[t[i]-'a'])
                    return false;
        return true;
    }
};
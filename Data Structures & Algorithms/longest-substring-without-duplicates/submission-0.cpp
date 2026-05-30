class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char,char> a; 
        int max_length = 0;
        int k=0;
        int start_index = 0;
        for(int i=start_index;i<s.size();i++) {
            if(a.find(s[i])==a.end()) {
                k++;
                a[s[i]]=1;
            }
            else {
                max_length = max(max_length,k);
                k = 0;
                a.clear();
                i = ++start_index;
                i--;
            }
        }
        return max(max_length,k);
    }
};
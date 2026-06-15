class Solution {
public:
    int numDecodings(string s) {
        int prev1 = 1;
        int prev2 = 0;
        if(s[0] != '0') prev2 = 1;
        int current = prev2;
        for(int i = 2; i <= s.size(); i++) {
            current = 0;
            if(s[i - 1] != '0') current += prev2;
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6' )) current += prev1;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }
};

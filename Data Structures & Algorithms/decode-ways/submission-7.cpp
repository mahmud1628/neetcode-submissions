class Solution {
    int numDecodings(string & s, int index, vector<int> & mem) {
        if(index < s.size() && s[index] == '0') return 0;
        if(index >= s.size() - 1) {
            return 1;
        }
        if(mem[index] != -1) return mem[index];

        char ch = s[index];
        char next_ch = s[index + 1];
        if(next_ch == '0' && ch < '3') {
            mem[index] = numDecodings(s, index + 2, mem);
        }
        else {
            int a = numDecodings(s, index  + 1, mem);
            int b = 0;
            if(!(ch >= '2' && next_ch >= '7') && ch < '3') {
                b = numDecodings(s, index + 2, mem);
            }
            mem[index] = a + b;
        }
        return mem[index];
    }
public:
    int numDecodings(string s) {
        vector<int> mem(s.size() + 1, 0);
        mem[0] = 1;
        if(s[0] != '0') mem[1] = 1;
        for(int i = 2; i <= s.size(); i++) {
            if(s[i - 1] != '0') mem[i] += mem[i - 1];
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6' )) mem[i] += mem[i - 2];
        }
        return mem[mem.size() - 1];
    }
};

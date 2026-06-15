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
        if(s[0] == '0') return 0;
        vector<int> mem(s.size(), -1);
        return numDecodings(s, 0, mem);
    }
};

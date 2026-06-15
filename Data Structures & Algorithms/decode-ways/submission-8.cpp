class Solution{
    public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n + 1, 0); 
        mem[n] = 1; 
        mem[n - 1] = (s[n - 1] != '0') ? 1 : 0; // If the last char is '0', it has 0 ways
        
        for(int i = n - 2; i >= 0; i--) {
            // If current char is '0', it can't decode into anything. Leave mem[i] as 0.
            if (s[i] == '0') {
                mem[i] = 0;
                continue;
            }
            
            // Single digit decoding jump
            int a = mem[i + 1];
            
            // Two digit decoding jump
            int b = 0;
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                b = mem[i + 2];
            }
            
            mem[i] = a + b;
        }
    
        return mem[0];
    }
};
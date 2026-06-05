class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; n != 0; i++) {
            if(n & 1) res = res | (1 << (31 - i));
            n = n >> 1; 
        }
        return res;
    }
};

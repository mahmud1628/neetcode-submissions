class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 0;
        while(n) {
            if(n & 1) res = res | (1 << (31 - i));
            i++;
            n = n >> 1;
        }
        return res;
    }
};

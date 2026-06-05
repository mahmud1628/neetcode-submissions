class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<uint8_t> s;
        while(n) {
            s.push((uint8_t) n & 1);
            n = n >> 1;
        } 
        int zeros = 32 - s.size();
        uint32_t product = 1;
        uint32_t result = 0;
        while(zeros--) {
            product *= 2;
        }
        while(s.size()) {
            if(s.top() == 1) result += product;
            product *= 2;
            s.pop();
        }
        return result;
    }
};

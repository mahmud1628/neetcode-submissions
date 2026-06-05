class Solution {
public:
    int getSum(int a, int b) {
        int pos = 0;
        uint8_t carry = 0;
        int sum = 0;

        while(pos < 32) {
            uint8_t lsb_a, lsb_b, s;
            lsb_a = a & 1;
            lsb_b = b & 1;
            s = lsb_a ^ lsb_b ^ carry;
            carry = (lsb_a & lsb_b) | (lsb_a & carry) | (lsb_b & carry);
            if(s) sum = sum | (1 << pos);
            pos++;
            a = a >> 1;
            b = b >> 1;
        }
        if(carry) sum = sum | (1 << pos);
        return sum;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int bit_position = 0;
        int sum_bit = 0;
        int carry_bit = 0;
        while(bit_position < 32) {
            int bit_a = (int) a & 1;
            int bit_b = (int) b & 1;
            sum_bit = (int) ((bit_a ^ bit_b) ^ carry_bit);
            carry_bit = (int)((bit_a & bit_b) | (bit_a | bit_b) & carry_bit);
            if(sum_bit) sum = sum | (1 << bit_position);
            bit_position++;
            a = a >> 1;
            b = b >> 1;
        }
        if(carry_bit && bit_position < 32) sum = sum | 1 << bit_position;
        return sum;
    }
};

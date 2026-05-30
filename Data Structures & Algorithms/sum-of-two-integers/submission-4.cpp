class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int c = (a & b) << 1; // carry
            a = a ^ b; // add without carry
            b = c;
        }
        return a;
    }
};

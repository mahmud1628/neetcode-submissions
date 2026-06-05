class Solution {
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            cnt += (int) n & 1;
            n = n >> 1;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for(int i = 0; i <= n; i++) output.push_back(hammingWeight(i));
        return output;
    }
};

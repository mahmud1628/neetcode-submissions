class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts;
        for(int i = 0; i <= n; i++)
            counts.push_back((int)(__builtin_popcount(i)));
        return counts;
    }
};

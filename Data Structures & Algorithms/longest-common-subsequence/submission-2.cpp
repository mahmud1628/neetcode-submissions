class Solution {
    int LCS(string & text1, string & text2, int index1, int index2, vector<vector<int>> & mem) {
        if(index1 == text1.size() || index2 == text2.size()) return 0;

        if(mem[index1][index2] == -1) {
            int l;
            if(text1[index1] == text2[index2]) l = 1 + LCS(text1, text2, index1 + 1, index2 + 1, mem);
            else {
                l = LCS(text1, text2, index1 + 1, index2, mem);
                l = max(l, LCS(text1, text2, index1, index2 + 1, mem));
            }
            mem[index1][index2] = l;
        }
        return mem[index1][index2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
        return LCS(text1, text2, 0, 0, mem);
    }
};

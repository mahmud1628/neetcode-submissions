class Solution {
    int recursiveLongestCommonSubsequence(int index1, int index2, string & text1, string & text2, vector<vector<int>> & mem) {
        if(index1 == text1.size() || index2 == text2.size()) return 0;

        if(mem[index1][index2] == -1) {
            if(text1[index1] == text2[index2]) mem[index1][index2] = 1 + recursiveLongestCommonSubsequence(index1 + 1, index2 + 1, text1, text2, mem);

            else mem[index1][index2] = max(recursiveLongestCommonSubsequence(index1 + 1, index2, text1, text2, mem), recursiveLongestCommonSubsequence(index1, index2 + 1, text1, text2, mem));
    
        }

        return mem[index1][index2];

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
        return recursiveLongestCommonSubsequence(0,0,text1,text2, mem);
    }
};

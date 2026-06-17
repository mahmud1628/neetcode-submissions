class Solution {
    int uniquePaths(int m, int n, int curr_m, int curr_n, vector<vector<int>> & mem) {
        if(curr_m == m && curr_n == n) return 1;
        if(curr_m > m || curr_n > n) return 0;

        if(mem[curr_m][curr_n] != -1) return mem[curr_m][curr_n];

        int right = uniquePaths(m, n, curr_m, curr_n + 1, mem);
        int down = uniquePaths(m, n, curr_m + 1, curr_n, mem);

        return mem[curr_m][curr_n] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return uniquePaths(m - 1, n - 1, 0, 0, mem);
    }
};

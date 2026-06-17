class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, 0));
        mem[m - 1][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int right = 0, down = 0;
                if(i != m - 1) down = mem[i + 1][j]; 
                if(j != n - 1) right = mem[i][j + 1];
                if(i != m - 1 || j != n - 1) mem[i][j] = right + down;
            }
        }

        return mem[0][0];
    }
};

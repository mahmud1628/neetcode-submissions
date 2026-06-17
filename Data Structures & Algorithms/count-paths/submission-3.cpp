class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 0); // each row has n columns
        row[n - 1] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int right = 0;
                int down = row[j];
                if(j != n - 1) right = row[j + 1];
                if(i != m - 1 || j != n - 1) row[j] = right + down;
            }
        }

        return row[0];
    }
};

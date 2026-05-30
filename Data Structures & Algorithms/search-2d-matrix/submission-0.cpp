class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int first_row = 0, last_row = matrix.size() - 1;

        int n = matrix.size() - 1, m = matrix[n].size() - 1;

        while(first_row <= last_row) {
            int mid_row = first_row + (last_row - first_row) / 2;

            if(matrix[mid_row][m] < target) first_row = mid_row + 1;
            else if(matrix[mid_row][0] > target) last_row = mid_row - 1;
            else {
                int left_column = 0, right_column = m;

                while(left_column <= right_column) {
                    int mid_column = left_column + (right_column - left_column) / 2;

                    int t = matrix[mid_row][mid_column];
                    if(t == target) return true;
                    else if(t > target) right_column = mid_column - 1;
                    else left_column = mid_column + 1;
                }
                return false;
            }
        }

        return false;

    }
};

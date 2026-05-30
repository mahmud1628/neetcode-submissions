class Solution {
public:
    bool isValidRows(vector<vector<char>> & board) {
        for(int row = 0; row < board.size(); row++) {
            vector<bool> visited(9, false);
            for(int col = 0; col < board[row].size(); col++) {
                if(board[row][col] == '.') continue;
                if(visited[board[row][col] - '0']) return false;
                else visited[board[row][col] - '0'] = true;
            }
        }
        return true;
    }

    bool isValidCols(vector<vector<char>> & board) {
        for(int col = 0; col < board.size(); col++) {
            vector<bool> visited(9, false);
            for(int row = 0; row < board[col].size(); row++) {
                if(board[row][col] == '.') continue;
                if(visited[board[row][col] - '0']) return false;
                else visited[board[row][col] - '0'] = true;
            }
        }
        return true;
    }
    bool isValidSubGrid(int startRow, int startCol, vector<vector<char>> & board) {
        vector<bool> visited(9, false);
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] == '.') continue;
                if(visited[board[i][j] - '0']) return false;
                else visited[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_valid = isValidRows(board);
        if(row_valid == false) return false;
        bool col_valid = isValidCols(board);
        if(col_valid == false) return false;

        for(int i = 0; i < board.size(); i+=3) {
            for(int j = 0; j < board.size(); j+=3) {
                bool grid_valid = isValidSubGrid(i,j,board);
                if(grid_valid == false) return false;
            }
        }
        return true;
    }
};

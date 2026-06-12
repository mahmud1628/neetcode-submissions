class Solution {
    bool exist(vector<vector<char>> & board, string word, int row, int column, int index) {
        if(index >= word.size()) return true;
        if(row < 0 || column < 0 || row >= board.size() || column >= board[row].size() || board[row][column] == '#') return false;

        if(word[index] != board[row][column]) return false;

        char current = board[row][column];
        board[row][column] = '#'; // mark as visited

        bool right = exist(board, word, row, column + 1, index + 1);
        if(right) return true;
        bool down = exist(board, word, row + 1, column, index + 1);        
        if(down) return true;
        bool left = exist(board, word, row, column - 1, index + 1);        
        if(left) return true;
        bool up = exist(board, word, row - 1, column, index + 1);    
        if(up) return true;

        board[row][column] = current; // remove visited mark

        return false;        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++) {
            for(int column = 0; column < board[row].size(); column++) {
                if(board[row][column] == word[0]) {
                    bool found = exist(board, word, row, column, 0);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};

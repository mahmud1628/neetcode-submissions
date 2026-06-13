struct Node {
    unordered_map<char, Node *> children;
    bool isCompleteWord;
    string word;
    Node() {
        isCompleteWord = false;
    }
};
class Solution {
    Node * root;
    void insert(string word, int index, Node * current_root) {
        if(index == word.size()) {
            current_root->isCompleteWord = true;
            current_root->word = word;
            return;
        }

        char current_char = word[index];

        if(current_root->children.find(current_char) == current_root->children.end()) {
            Node * node = new Node();
            current_root->children[current_char] = node;
        }

        insert(word, index + 1, current_root->children[current_char]);
    }

    void search(vector<vector<char>> & board, int row, int column, Node * current_root, vector<string> & result) {
        if(current_root->isCompleteWord) {
            result.push_back(current_root->word);
            current_root->isCompleteWord = false;
        }
        if(row < 0 || column < 0 || row >= board.size() || column >= board[0].size() || board[row][column] == '#') {
            return;
        }

        char current_char = board[row][column];

        if(current_root->children.find(current_char) == current_root->children.end()) return;

        board[row][column] = '#';
        Node * next_root = current_root->children[current_char];
        search(board, row + 1, column, next_root, result);
        search(board, row - 1, column, next_root, result);
        search(board, row, column + 1, next_root, result);
        search(board, row, column - 1, next_root, result);
        board[row][column] = current_char;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        // build the trie using the strings in the words vector
        for(string word : words) 
            insert(word, 0, root);

        vector<string> res;

        //search in the trie starting from each cell of the board
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                search(board, i, j, root, res);
        
        return res;
    }
};

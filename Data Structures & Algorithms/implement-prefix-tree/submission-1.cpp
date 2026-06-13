struct Node {
    Node * children[26];
    bool isCompleteWord;
    Node() {
        isCompleteWord = false;
        for(int i = 0; i < 26; i++) 
            children[i] = nullptr;
    }
};

class PrefixTree {
    Node * root;
    void insert(string word, int index, Node * current_root) {
        if(index == word.size()) {
            current_root->isCompleteWord = true;
            return;
        }
        char current_char = word[index];
        if(current_root->children[current_char - 'a'] == nullptr) {
            Node * node = new Node();
            current_root->children[current_char - 'a'] = node;
            insert(word, index + 1, node);
        } else {
            insert(word, index + 1, current_root->children[current_char - 'a']);
        }
    }

    bool search(string word, int index, Node * current_root) {
        if(index == word.size()) {
            return current_root->isCompleteWord;
        }

        char current_char = word[index];

        if(current_root->children[current_char - 'a'] == nullptr) return false;

        return search(word, index + 1, current_root->children[current_char - 'a']);
    }

    bool startsWith(string prefix, int index, Node * current_root) {
        if(index == prefix.size()) {
            return true;
        }

        char current_char = prefix[index];

        if(current_root->children[current_char - 'a'] == nullptr) return false;

        return startsWith(prefix, index + 1, current_root->children[current_char - 'a']);
    }
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        insert(word, 0, root);
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix, 0, root);
    }
};

struct Node {
    unordered_map<char, Node *> children;
    bool isCompleteWord;
    Node() {
        isCompleteWord = false;
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
        if(current_root->children.find(current_char) == current_root->children.end()) {
            Node * node = new Node();
            current_root->children[current_char] = node;
            insert(word, index + 1, node);
        } else {
            insert(word, index + 1, current_root->children[current_char]);
        }
    }

    bool search(string word, int index, Node * current_root) {
        if(index == word.size()) {
            return current_root->isCompleteWord;
        }

        char current_char = word[index];

        if(current_root->children.find(current_char) == current_root->children.end()) return false;

        return search(word, index + 1, current_root->children[current_char]);
    }

    bool startsWith(string prefix, int index, Node * current_root) {
        if(index == prefix.size()) {
            return true;
        }

        char current_char = prefix[index];

        if(current_root->children.find(current_char) == current_root->children.end()) return false;

        return startsWith(prefix, index + 1, current_root->children[current_char]);
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

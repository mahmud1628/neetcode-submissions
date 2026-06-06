/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string serialized = "";
        q.push(root);

        while(q.size()) {
            TreeNode * node = q.front();
            q.pop();
            if(node) {
                serialized += to_string(node->val) + "|";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                serialized += "N|";
            }
        }
        return serialized;
    }
    /*
        My serialize strategy:
            Put a | after each node value to separate node values in the string
            Put - for null values in the string
            Run BFS to encode each node
    */

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> nodes;
        queue<TreeNode*> current_roots;

        int start = 0, len;

        for(int i = 0; i < data.size(); i++) {
            if(data[i] == 'N') {
                TreeNode * node = nullptr;
                nodes.push(node);
                i++;
                start = i + 1;
            }
            else if(data[i] == '|') {
                len = i - start;
                string val = data.substr(start, len);
                TreeNode * node = new TreeNode(stoi(val));
                nodes.push(node);
                start = i + 1;
            } 
        }

        TreeNode * root = nodes.front();
        current_roots.push(root);
        nodes.pop();
        while(nodes.size()) {
            int current_root_size = current_roots.size();
            for(int i = 0; i < current_root_size; i++) {
                TreeNode * curr_root = current_roots.front();
                current_roots.pop();
                TreeNode * left = nodes.front();
                nodes.pop();
                TreeNode * right = nodes.front();
                nodes.pop();
                curr_root->left = left;
                curr_root->right = right;
                if(left) current_roots.push(left);
                if(right) current_roots.push(right);
            }
        }
        return root;
    }
};

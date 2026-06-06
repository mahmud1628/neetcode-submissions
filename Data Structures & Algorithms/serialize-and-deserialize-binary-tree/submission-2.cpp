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
    string negative = "N";
    string separator = "|";
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
                serialized += to_string(node->val) + separator;
                q.push(node->left);
                q.push(node->right);
            }
            else {
                serialized += negative + separator;
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
            if(data[i] == negative[0]) {
                TreeNode * node = nullptr;
                nodes.push(node);
                i++;
                start = i + 1;
            }
            else if(data[i] == separator[0]) {
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
        while(nodes.size() && current_roots.size()) {
            TreeNode * curr_root = current_roots.front();
            current_roots.pop();
            TreeNode * left = nodes.front();
            nodes.pop();
            if(left) {
                curr_root->left = left;
                current_roots.push(left);
            }
            TreeNode * right = nodes.front();
            nodes.pop();
            if(right) {
                curr_root->right = right;
                current_roots.push(right);
            }
        }
        return root;
    }
};

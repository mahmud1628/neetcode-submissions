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

class Solution {
    TreeNode* buildTree(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, unordered_map<int, int> & node_inorder_index) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode * root = new TreeNode(preorder[preStart]);

        int root_inorder_index = node_inorder_index[preorder[preStart]];
        int nodes_on_left_of_root = root_inorder_index - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + nodes_on_left_of_root, inorder, inStart, root_inorder_index - 1, node_inorder_index);
        root->right = buildTree(preorder, preStart + nodes_on_left_of_root + 1, preEnd, inorder, root_inorder_index + 1, inEnd, node_inorder_index);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> node_inorder_index;
        for(int i = 0; i < inorder.size(); i++) node_inorder_index[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, node_inorder_index);
    }
};

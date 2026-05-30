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
    TreeNode * buildTree(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, unordered_map<int,int> node_index) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode * root = new TreeNode(preorder[preStart]);

        int index = node_index[preorder[preStart]];
        int remaining = index - inStart;

        root->left = buildTree(preorder,preStart+1, preStart + remaining, inorder,inStart,index - 1, node_index);
        root->right = buildTree(preorder,preStart + remaining + 1, preEnd, inorder, index + 1, inEnd, node_index);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> node_index;
        for(int i=0;i<inorder.size();i++) node_index[inorder[i]] = i;
        TreeNode * root = buildTree(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1, node_index);
        return root;
    }
};

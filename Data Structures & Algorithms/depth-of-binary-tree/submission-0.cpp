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
    int helper(TreeNode * root) {
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max_left = 1 + maxDepth(root->left);
        int max_right = 1 + maxDepth(root->right);
        return max(max_left,max_right);
    }
};

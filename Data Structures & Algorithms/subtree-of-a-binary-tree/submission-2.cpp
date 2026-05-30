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

    bool match(TreeNode* root, TreeNode* subroot) {
        if(!root && !subroot) return true;
        if((root && !subroot) || (!root && subroot)) return false;
        if(root->val == subroot->val) return match(root->left, subroot->left) && match(root->right,subroot->right);
        return false;
    }


public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root == subRoot) return true; // tree could also be coonsidered a subtree of itself
        if(match(root,subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
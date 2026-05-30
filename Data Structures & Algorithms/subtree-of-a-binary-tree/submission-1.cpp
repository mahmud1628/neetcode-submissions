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

    void preOrder(TreeNode* root, TreeNode* subroot, bool &isSubTree) {

        if(root == nullptr) return;

        if(match(root,subroot)) {
            isSubTree = true;
            return;
        }

        preOrder(root->left, subroot,isSubTree);
        preOrder(root->right, subroot,isSubTree);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == subRoot) return true; // tree could also be coonsidered a subtree of itself

        bool isSubTree = false;

        preOrder(root,subRoot,isSubTree);

        return isSubTree;

    }
};

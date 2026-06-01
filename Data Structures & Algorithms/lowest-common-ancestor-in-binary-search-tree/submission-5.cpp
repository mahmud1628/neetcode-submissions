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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(p->val < root->val && q->val < root->val) root = root->left; // if both p and q are less than root, then answer is in left subtree
            else if(p->val > root->val && q->val > root->val) root = root->right; // if both p and q are greater than root, then answer is in right subtree
            else return root; // if one of p and q is less than root and the other is greater than root, then this root is the answer
        }
        return nullptr;
    }
};

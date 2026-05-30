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
    bool helper(TreeNode * p, TreeNode * q) {
        if((p && !q) || (q && !p)) return false;
        if(p && q && p->val != q->val) return false;
        if(p->left || q->left) return isSameTree(p->left,q->left);
        if(p->right || q->right) return isSameTree(p->right,q->right);
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        return helper(p,q);
    }
};

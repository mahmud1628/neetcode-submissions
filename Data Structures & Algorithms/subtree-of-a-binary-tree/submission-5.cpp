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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        bool val = p->val == q->val;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return val && left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* match = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            TreeNode* temp = q.front();
            if(temp->val == subRoot->val) {
                match = temp;
                bool b = isSameTree(subRoot, match);
                if(b) return true;
            }
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false;
    }
};

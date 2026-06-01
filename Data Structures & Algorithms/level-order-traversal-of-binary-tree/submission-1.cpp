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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> q;
        int d = 0;
        res.push_back({});
        q.push({d, root});
        while(q.size()) {
            pair<int, TreeNode*> p = q.front();
            q.pop();
            TreeNode* node = p.second;
            if(node->left) q.push({p.first + 1, node->left});
            if(node->right) q.push({p.first + 1, node->right});
            if(d == p.first) {
                res[d].push_back(node->val);
            } 
            else {
                d++;
                res.push_back({node->val});
            }
        }

        return res;
    }
};

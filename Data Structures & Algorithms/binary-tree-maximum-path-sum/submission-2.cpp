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
    /*
        This function returns the maximum possible path sum obtained from the current node if we don't split from current node, that is, we can take either the left subtree or the right subtree in the path
    */
    int MPS(TreeNode* root, int & max_path_sum) {
        int l = 0, r = 0;
        if(root->left) l = MPS(root->left, max_path_sum);
        if(root->right) r = MPS(root->right, max_path_sum);
        int spliting_path_sum = root->val + l + r; // path sum considering we are spliting from current node
        if(spliting_path_sum > max_path_sum) max_path_sum = spliting_path_sum;
        int non_spliting_path_sum = root->val + max(max(l, r), 0);
        if(non_spliting_path_sum > max_path_sum) max_path_sum = non_spliting_path_sum;
        return non_spliting_path_sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        MPS(root, max_path_sum);
        return max_path_sum;
    }
};

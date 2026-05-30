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

    void inorder(TreeNode* root, vector<int> & arr) {
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
public:
    bool isValidBST(TreeNode* root) {
        // inorder traversal gives a sorted sequence in a BST
        vector<int> arr;
        inorder(root,arr);
        for(int i=0;i<arr.size()-1;i++) {
            if(arr[i] >= arr[i+1]) return false;
        }
        return true;
    }
};

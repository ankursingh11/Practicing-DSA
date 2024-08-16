
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

    void findPreorder(TreeNode*root, vector<int>&arr){
        if(!root) return;
        arr.push_back(root->val);
        findPreorder(root->left, arr);
        findPreorder(root->right, arr);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        findPreorder(root, preorder);
        return preorder;
    }
};
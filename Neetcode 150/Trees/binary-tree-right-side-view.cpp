
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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

    void rightView(TreeNode*root, vector<int>&ans, int level){
        if(!root) return;
        if(level == ans.size()) ans.push_back(root->val);
        rightView(root->right, ans, level+1);
        rightView(root->left, ans, level+1);
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        rightView(root, ans, 0);
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

    int maxPathSumHelper(TreeNode*root, int &ans){
        if(!root) return 0;
        int leftAns = max(0, maxPathSumHelper(root->left, ans));
        int rightAns = max(0, maxPathSumHelper(root->right, ans));
        ans = max(ans, root->val + leftAns + rightAns);
        return root->val + max(leftAns, rightAns);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        if(!root) return ans;
        maxPathSumHelper(root, ans);
        return ans;
    }
};

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

    void solve(TreeNode*root, int k, int &i, int &ans){
        if(!root) return;

        solve(root->left, k, i, ans);
        i+=1;
        if(i == k){
            ans = root->val;
            return;
        }

        solve(root->right, k, i, ans);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        if(!root) return ans;

        int i = 0;
        solve(root, k, i, ans);
        
        return ans;
    }
};
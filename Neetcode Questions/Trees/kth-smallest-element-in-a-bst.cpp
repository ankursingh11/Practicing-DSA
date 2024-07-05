
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

    void kthSmallestHelper(TreeNode*root, int &i, int k, int&ans){
        if(!root) return;
        kthSmallestHelper(root->left, i, k, ans);
        i+=1;
        if(i == k){
            ans = root->val;
            return;
        }
        kthSmallestHelper(root->right, i, k, ans);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        if(!root) return ans;
        int i = 0;
        kthSmallestHelper(root, i, k, ans);
        return ans;
    }
};
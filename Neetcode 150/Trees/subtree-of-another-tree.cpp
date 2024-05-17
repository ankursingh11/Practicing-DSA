
// https://leetcode.com/problems/subtree-of-another-tree/description/

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

    bool ans = false;

    bool sameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if( !p || !q ) return false;
        if(p->val != q->val) return false;
        return sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }

    void solve(TreeNode* root, TreeNode* subRoot){
        if(!root) return;
        if(ans) return;

        if(root->val == subRoot->val){
            ans = sameTree(root, subRoot);
            if(ans) return;
        }

        solve(root->left, subRoot);
        solve(root->right, subRoot);
        return;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solve(root, subRoot);
        return ans;
    }
};
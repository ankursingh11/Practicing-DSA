
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

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

class Node{
    public:
    int minNode, maxNode, sum;
    bool isBST;

    Node(int minNode, int maxNode, int sum, bool isBST){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
public:

    int ans = 0;

    Node solve(TreeNode*root){
        if(!root) return Node(INT_MAX, INT_MIN, 0, true);

        auto leftAns = solve(root->left);
        auto rightAns = solve(root->right);

        int currMin = min({root->val, leftAns.minNode, rightAns.minNode});
        int currMax = max({root->val, leftAns.maxNode, rightAns.maxNode});
        int currSum = root->val + leftAns.sum + rightAns.sum;
        bool isBST = (
            leftAns.isBST 
            && root->val > leftAns.maxNode 
            && rightAns.isBST
            && root->val < rightAns.minNode
        );

        if(isBST) ans = max(ans, currSum);

        return Node(currMin, currMax, currSum, isBST);
    }

    int maxSumBST(TreeNode* root) {
        if(!root) return ans;
        solve(root);
        return ans;
    }
};
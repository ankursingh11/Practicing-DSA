
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

    void solve(TreeNode*root, vector<int>&arr){
        if(!root) return;
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        vector<int> arr;
        solve(root, arr);

        int start = 0, end = arr.size()-1;
        while(start < end){
            int currSum = arr[start] + arr[end];
            if(currSum == k) return true;
            else if(currSum < k) start++;
            else end--;
        }

        return false;
    }
};
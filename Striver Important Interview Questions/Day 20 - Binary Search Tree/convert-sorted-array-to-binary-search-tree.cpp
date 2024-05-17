
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    TreeNode* sortedArrayToBSTHelper(vector<int>&nums, int si, int ei){
        if(si > ei) return NULL;
        int mid = si + (ei - si)/2;
        int rootData = nums[mid];
        TreeNode*root = new TreeNode(rootData);
        root->left = sortedArrayToBSTHelper(nums, si, mid-1);
        root->right = sortedArrayToBSTHelper(nums, mid+1, ei);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
    }
};
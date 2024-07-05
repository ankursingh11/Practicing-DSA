
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    
    bool check(vector<int>&arr){
        int n = arr.size();
        int X = arr[n-1];
        for(auto ele : arr){
            if(ele > X) return false;
        }
        return true;
    }
    
    void solve(TreeNode*root, vector<int>arr, int &ans){
        
        if(!root) return;
        
        arr.push_back(root->val);
        if(check(arr)) ans++;
        
        solve(root->left, arr, ans);
        solve(root->right, arr, ans);
        arr.pop_back();
        return;
    }
    
    int goodNodes(TreeNode* root) {
        vector<int> arr;
        int ans = 0;
        if(!root) return ans;
        solve(root, arr, ans);
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> smallAns;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
        
            if(!curr){
                if(q.empty()) break;
                ans.push_back(smallAns);
                smallAns.erase(smallAns.begin(), smallAns.end());
                q.push(NULL);
                continue;
            }

            smallAns.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(smallAns);
        return ans;
    }
};
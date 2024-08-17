
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
        vector<int> currentLevel;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            if(!front){
                if(q.empty()) break;
                ans.push_back(currentLevel);
                currentLevel.clear();
                q.push(NULL);
                continue;
            }

            currentLevel.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        ans.push_back(currentLevel);
        return ans;
    }
};
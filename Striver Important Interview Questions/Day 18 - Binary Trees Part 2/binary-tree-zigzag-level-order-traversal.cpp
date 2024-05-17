
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> subAns;
        
        bool flag = true;
        
        while(!q.empty()){
            TreeNode*front = q.front();
            q.pop();
            
            if(!front){
                if(q.empty()) break;
                
                if(flag) ans.push_back(subAns);
                else{
                    reverse(subAns.begin(), subAns.end());
                    ans.push_back(subAns);
                }
                flag = !flag;
                q.push(NULL);
                subAns.clear();
                continue;
            }
            
            subAns.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        
         if(flag) ans.push_back(subAns);
        else{
            reverse(subAns.begin(), subAns.end());
            ans.push_back(subAns);
        }
        
        return ans;
    
    }
};
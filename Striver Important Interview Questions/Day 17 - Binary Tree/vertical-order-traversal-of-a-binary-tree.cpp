
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode*curr = front.first;
            int vertical = front.second.first;
            int level = front.second.second;

            mp[vertical][level].insert(curr->val);

            if(curr->left) q.push({curr->left, {vertical-1, level+1}});
            if(curr->right) q.push({curr->right, {vertical+1, level+1}});
        }

        for(auto it1 : mp){
            vector<int> smallAns;
            for(auto it2 : it1.second){
                smallAns.insert(smallAns.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(smallAns);
        }

        return ans;
    }
};
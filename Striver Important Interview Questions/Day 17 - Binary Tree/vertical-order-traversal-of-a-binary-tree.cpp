
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode*currNode = front.first;
            int vertical = front.second.first;
            int level = front.second.second;

            mp[vertical][level].insert(currNode->val);

            if(currNode->left) q.push({currNode->left, {vertical-1, level+1}});
            if(currNode->right) q.push({currNode->right, {vertical+1, level+1}});
        }

        for(auto itr1 : mp){
            vector<int> smallAns;
            for(auto itr2 : itr1.second){
                smallAns.insert(smallAns.end(), itr2.second.begin(), itr2.second.end());
            }
            ans.push_back(smallAns);
        }

        return ans;
    }
};


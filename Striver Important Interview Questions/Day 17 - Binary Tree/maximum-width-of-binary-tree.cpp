
// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {

        double ans = 0;
        if(!root) return ans;

        queue<pair<TreeNode*, double>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            double first, last;
            double minIndex = q.front().second;

            for(int i = 0; i < n; i++){
                auto front = q.front();
                q.pop();
                auto currNode = front.first;
                double currIndex = front.second - minIndex;

                if(i == 0) first = currIndex;
                if(i == n-1) last = currIndex;

                if(currNode->left) q.push({currNode->left, 2*currIndex+1});
                if(currNode->right) q.push({currNode->right, 2*currIndex+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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

    TreeNode* buildTreeHelper(int inS, int inE, vector<int>&inorder, int postS, int postE, vector<int>&postorder){
        if(inS > inE || postS > postE) return NULL;

        int rootData = postorder[postE];
        TreeNode*root = new TreeNode(rootData);
        int rootIndex = -1;
        for(int i = inS; i <= inE; i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }

        int LinS = inS;
        int LinE = rootIndex-1;
        int RinS = rootIndex+1;
        int RinE = inE;

        int LpostS = postS;
        int LpostE = LpostS + (LinE - LinS);
        int RpostS = LpostE+1;
        int RpostE = postE-1;

        root->left = buildTreeHelper(LinS, LinE, inorder, LpostS, LpostE, postorder);
        root->right = buildTreeHelper(RinS, RinE, inorder, RpostS, RpostE, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inS = 0;
        int inE = inorder.size()-1;
        int postS = 0;
        int postE = postorder.size()-1;

        return buildTreeHelper(inS, inE, inorder, postS, postE, postorder);
    }
};
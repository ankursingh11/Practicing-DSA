
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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

    TreeNode* constructTree(vector<int>&preorder, int preS, int preE, vector<int>&inorder, int inS, int inE){
        if(preS > preE || inS > inE) return NULL;

        int rootData = preorder[preS];
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

        int LpreS = preS+1;
        int LpreE = LpreS + (LinE - LinS);
        int RpreS = LpreE+1;
        int RpreE = preE;

        root->left = constructTree(preorder, LpreS, LpreE, inorder, LinS, LinE);
        root->right = constructTree(preorder, RpreS, RpreE, inorder, RinS, RinE);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preS = 0;
        int preE = preorder.size()-1;
        int inS = 0;
        int inE = inorder.size()-1;

        return constructTree(preorder, preS, preE, inorder, inS, inE);
    }
};
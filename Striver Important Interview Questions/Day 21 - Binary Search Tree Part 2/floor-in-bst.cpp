
// https://www.naukri.com/code360/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int>*root, int X, int &ans){
    if(!root) return;

    if(root->val <= X) ans = max(ans, root->val);
    if(X < root->val) solve(root->left, X, ans);
    if(X > root->val) solve(root->right, X, ans);
    return;
}


int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root) return -1;
    
    int ans = -1;
    solve(root, X, ans);
    return ans;
}
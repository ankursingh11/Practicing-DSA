
// https://www.naukri.com/code360/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void solve(BinaryTreeNode<int>*root, int x, int &ans){
    if(!root) return;
    if(root->data >= x) ans = min(ans, root->data);
    if(x < root->data) solve(root->left, x, ans);
    if(x > root->data) solve(root->right, x, ans);
    return;
}

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ans = INT_MAX;
    if(!root) return ans;
    solve(root, x, ans);
    return ans == INT_MAX ? -1 : ans;
}
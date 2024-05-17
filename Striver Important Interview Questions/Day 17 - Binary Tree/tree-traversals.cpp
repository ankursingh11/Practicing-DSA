
// https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    if(!root) return ans;
    
    vector<int> preorder, inorder, postorder;
    stack<pair<int, BinaryTreeNode<int>*>> st;
    st.push({1, root});
    
    while(!st.empty()){
        auto top = st.top();
        st.pop();
        int level = top.first;
        BinaryTreeNode<int>* curr = top.second;

        if(level == 1){
            preorder.push_back(curr->data);
            level++;
            st.push({level, curr});
            if(curr->left) st.push({1, curr->left});
        }else if(level == 2){
            inorder.push_back(curr->data);
            level++;
            st.push({level, curr});
            if(curr->right) st.push({1, curr->right});
        }else postorder.push_back(curr->data);
    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}


















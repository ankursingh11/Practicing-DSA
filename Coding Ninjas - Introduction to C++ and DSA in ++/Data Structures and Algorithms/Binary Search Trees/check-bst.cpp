
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
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

***********************************************************/
#include<bits/stdc++.h>

bool isBSTHelper(BinaryTreeNode<int>*root, int minValue, int maxValue){
    if(!root) return true;
    if(root->data < minValue || root->data > maxValue) return false;
    return isBSTHelper(root->left, minValue, root->data-1) && isBSTHelper(root->right, root->data, maxValue);
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    return isBSTHelper(root, INT_MIN, INT_MAX);
}
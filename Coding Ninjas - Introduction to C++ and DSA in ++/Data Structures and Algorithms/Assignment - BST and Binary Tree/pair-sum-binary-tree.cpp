

#include<bits/stdc++.h>

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

void inorder(BinaryTreeNode<int>*root, vector<int>&arr){
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(!root) return;

    vector<int> arr;
    inorder(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size()-1;
    while(i < j){
        if(arr[i] + arr[j] == sum) cout<<arr[i++]<<" "<<arr[j--]<<endl;
        else if(arr[i] + arr[j] < sum) i++;
        else j--;
    }

    return;
}
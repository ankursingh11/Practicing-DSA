
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return;
    vector<vector<int>> ans;
    vector<int> smallAns;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    bool flag = true;
    while(!q.empty()){
        BinaryTreeNode<int>*currNode = q.front();
        q.pop();
        if(!currNode){
            if(q.empty()) break;
            if(flag) ans.push_back(smallAns);
            else{
                reverse(smallAns.begin(), smallAns.end());
                ans.push_back(smallAns);
            }
            flag = !flag;
            q.push(NULL);
            smallAns.clear();
            continue;
        }
        smallAns.push_back(currNode->data);
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }

    if(flag) ans.push_back(smallAns);
    else{
        reverse(smallAns.begin(), smallAns.end());
        ans.push_back(smallAns);
    }

    for(auto arr : ans){
        for(auto ele : arr) cout<<ele<<" ";
        cout<<endl;
    }

    return;
}
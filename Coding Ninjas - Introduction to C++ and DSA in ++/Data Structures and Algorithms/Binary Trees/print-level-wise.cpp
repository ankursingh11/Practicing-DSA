
// Following is the Binary Tree node structure
/**************
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
***************/
#include<bits/stdc++.h>
using namespace std;
#define BT BinaryTreeNode<int>

void printLevelWise(BinaryTreeNode<int> *root) {
			if(!root) return;
			
			queue<BT*> q;
			q.push(root);
			
			while(!q.empty()){
				BT*front = q.front();
				q.pop();
				
				//printing left node
				cout<<front->data<<":";
				if(front->left){
					cout<<"L:"<<front->left->data<<",";
					q.push(front->left);
				}else{
					cout<<"L:-1,";
				}
				
				//printing right node
				if(front->right){
					cout<<"R:"<<front->right->data;
					q.push(front->right);
				}else{
					cout<<"R:-1";
				}
				cout<<endl;
			}
		}
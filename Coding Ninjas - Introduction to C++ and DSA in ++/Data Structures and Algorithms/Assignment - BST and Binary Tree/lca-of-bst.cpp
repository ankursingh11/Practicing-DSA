
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
#define BT BinaryTreeNode<int>*

BT helper(BT root, int a, int b){
    if(!root) return root;
    if(root->data == a || root->data == b) return root;
    if(root->data < a && root->data < b) return helper(root->right, a, b);
    if(root->data > a && root->data > b) return helper(root->left, a, b);
    else{
        BT leftAns = helper(root->left, a, b);
        BT rightAns = helper(root->right, a, b);
        if(leftAns && rightAns) return root;
        if(leftAns) return leftAns;
        else return rightAns;
    }
}

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(!root) return -1;
    BT ans = helper(root, val1, val2);
    if(ans) return ans->data;
    else return -1;
}
k
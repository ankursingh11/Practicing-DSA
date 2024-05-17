
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

BinaryTreeNode<int>* getLCAHelper(BinaryTreeNode<int>*root, int a, int b){
    if(!root) return root;
    if(root->data == a || root->data == b) return root;
    BinaryTreeNode<int>* leftAns = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int>*rightAns = getLCAHelper(root->right, a, b);
    if(leftAns && rightAns) return root;
    if(leftAns) return leftAns;
    else return rightAns;
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(!root) return -1;
    return getLCAHelper(root, a, b)->data;
}
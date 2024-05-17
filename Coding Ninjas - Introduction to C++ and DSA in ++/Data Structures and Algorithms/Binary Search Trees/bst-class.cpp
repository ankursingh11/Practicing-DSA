
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
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
	};

***********************************************************/

vector<int>* getPath(BinaryTreeNode<int> *root, int data) {
	// Write your code here
	if(!root) return NULL;

	if(root->data == data){
		vector<int>*ans = new vector<int>();
		ans->push_back(root->data);
		return ans;
	}

	if(data < root->data){
		vector<int>*leftAns = getPath(root->left, data);
		if(leftAns) leftAns->push_back(root->data);
		return leftAns;
	}

	if(data > root->data){
		vector<int>*rightAns = getPath(root->right, data);
		if(rightAns) rightAns->push_back(root->data);
		return rightAns;
	}
}
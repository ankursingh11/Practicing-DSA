
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

void rootToLeafPathsSumToKHelper(BinaryTreeNode<int>*root, vector<int>&path, int k){
    if(!root) return;
    path.push_back(root->data);
    k = k - root->data;

    if(!root->left && !root->right){
        if(k == 0){
            for(auto node : path) cout<<node<<" ";
            cout<<endl;
            path.pop_back();
            return;
        }
    }

    rootToLeafPathsSumToKHelper(root->left, path, k);
    rootToLeafPathsSumToKHelper(root->right, path, k);
    path.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    if(!root) return;
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, path, k);
}
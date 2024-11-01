
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int sumOfNodes_helper(TreeNode<int>*root){
    if(root->children.size() == 0) return root->data;
    int ans = root->data;
    for(int i = 0; i < root->children.size(); i++){
        ans = ans + sumOfNodes_helper(root->children[i]);
    }
    return ans;
}


int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int ans = 0;
    if(!root) return ans;
    return sumOfNodes_helper(root);
}

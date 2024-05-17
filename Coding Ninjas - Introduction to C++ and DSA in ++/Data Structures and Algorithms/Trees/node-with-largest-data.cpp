
// Following is the given Tree node structure.
/**************
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
***************/

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(!root) return root;
    TreeNode<int>*maxNode = root;
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>*temp = maxDataNode(root->children[i]);
        if(temp->data > maxNode->data) maxNode = temp;
    }
    return maxNode;
}


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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(!root) return root;
    TreeNode<int>*ans = NULL;
    if(root->data > x) ans = root;
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>*temp = getNextLargerElement(root->children[i], x);
        if(!ans || (temp && ans->data > temp->data)) ans = temp;
    }
    return ans;
}
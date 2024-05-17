
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

int height(TreeNode<int>* root) {
    if (!root) return 0;
    int ans = 0;
    for(int i = 0; i < root->children.size(); i++) ans = max(ans, height(root->children[i]));
    return 1 + ans;
}
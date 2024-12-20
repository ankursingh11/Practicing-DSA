
// Following is the given Tree node structure
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

void replaceWithDepthValue(TreeNode<int>*root, int d){
    root->data = d;
    for(int i = 0; i < root->children.size(); i++)
        replaceWithDepthValue(root->children[i], d+1);
}

void replaceWithDepthValue(TreeNode<int> *root){    
    replaceWithDepthValue(root, 0);
}


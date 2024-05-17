
// Following is the Tree node structure
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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(!root1 && !root2) return true;
    if( (!root1 && root2 ) || (root1 && !root2) ) return false;
    if( root1->data != root2->data && root1->children.size() != root2->children.size()) return false;
    
    for(int i = 0; i < root1->children.size();){
        if(isIdentical(root1->children[i], root2->children[i])) i++;
        else return false;
    }
    return true;
}

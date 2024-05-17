
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

int helper(BinaryTreeNode<int>*root, int sum){
    if(!root) return sum;
    sum = helper(root->right, sum);
    sum+=root->data;
    root->data = sum;
    sum = helper(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return;
    helper(root, 0);

}

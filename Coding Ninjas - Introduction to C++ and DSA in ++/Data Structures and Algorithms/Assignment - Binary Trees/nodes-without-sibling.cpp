
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return;
    if(root->left && !root->right) cout<<root->left->data<<" ";
    if(!root->left && root->right) cout<<root->right->data<<" ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    return;
}

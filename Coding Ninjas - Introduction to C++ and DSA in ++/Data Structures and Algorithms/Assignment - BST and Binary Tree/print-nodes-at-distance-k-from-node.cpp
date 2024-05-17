
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

void printNodes(BinaryTreeNode<int>*root, int k){
    if(!root) return;
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    printNodes(root->left, k-1);
    printNodes(root->right, k-1);
    return;
}

int nodesAtDistanceKHelper(BinaryTreeNode<int>*root, int node, int k){
    if(!root) return -1;
    if(root->data == node){
        printNodes(root, k);
        return 0;
    }

    int leftDistance = nodesAtDistanceKHelper(root->left, node, k);
    if(leftDistance != -1){
        if(leftDistance+1 == k) cout<<root->data<<endl;
        else printNodes(root->right, k-leftDistance-2);
        return (1+leftDistance);
    }

    int rightDistance = nodesAtDistanceKHelper(root->right, node, k);
    if(rightDistance != -1){
        if(rightDistance+1 == k) cout<<root->data<<endl;
        else printNodes(root->left, k-rightDistance-2);
        return (1+rightDistance);
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    if(!root) return;
    nodesAtDistanceKHelper(root, node, k);
    return;
}
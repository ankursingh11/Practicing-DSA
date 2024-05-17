
// https://www.naukri.com/code360/problems/all-root-to-leaf-paths-in-binary-tree._983599?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/

bool isLeaf(BinaryTreeNode<int>*root){
    return !root->left && !root->right;
}

void allPathFromRootToLeaf(BinaryTreeNode<int>*root, vector<string> &ans, string path){
    if(isLeaf(root)){
        path += to_string(root->data) + " ";
        ans.push_back(path);
        path.pop_back();
        path.pop_back();
        return;
    }
    path +=  to_string(root->data) + " ";
    if(root->left) allPathFromRootToLeaf(root->left, ans, path);
    if(root->right) allPathFromRootToLeaf(root->right, ans, path);
    return;
}


vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<string> ans;
    if(!root) return ans;
    string path = "";
    allPathFromRootToLeaf(root, ans, path);
    return ans;
}
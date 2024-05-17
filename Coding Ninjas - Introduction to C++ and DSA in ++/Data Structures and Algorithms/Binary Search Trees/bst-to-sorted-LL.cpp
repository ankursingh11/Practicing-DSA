
// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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

void helper(BinaryTreeNode<int>*root, vector<int>&v){
    if(!root) return;
    helper(root->left, v);
    v.push_back(root->data);
    helper(root->right, v);
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    vector<int>v;
    helper(root, v);
    Node<int>*head = NULL;
    Node<int>*tail = NULL;
    
    for(int i = 0; i < v.size(); i++){
        Node<int>*newNode = new Node<int>(v[i]);
        if(!head) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}
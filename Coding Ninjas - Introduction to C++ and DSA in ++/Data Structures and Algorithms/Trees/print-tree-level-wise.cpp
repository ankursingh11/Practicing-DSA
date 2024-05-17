
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

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    if(!root) return;

    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>*currNode = q.front();
        q.pop();
        cout<<currNode->data<<":";
        for(int i = 0; i < currNode->children.size(); i++){
            if(i == currNode->children.size()-1){
                cout<<currNode->children[i]->data;
            }else cout<<currNode->children[i]->data<<",";
            q.push(currNode->children[i]);
        }
        cout<<endl;
    }

    return;
}


// https://www.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        int i=1;
        queue<node*> q;
        q.push(root0);
        while(i<vec.size() and !q.empty()){
            node* front = q.front();
            node* nn = newNode(vec[i]);
            if(!front->left){
                front->left=nn;
            }
            else{
                front->right=nn;
                q.pop();
            }
            i++;
            q.push(nn);
        }
    }

};
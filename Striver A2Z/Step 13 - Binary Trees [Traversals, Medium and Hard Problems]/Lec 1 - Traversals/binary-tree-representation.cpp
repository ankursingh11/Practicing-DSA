
// https://www.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

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

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
#include<bits/stdc++.h>

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    queue<TreeNode<int>*>q;
    vector<int>v;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int>*front = q.front();
        q.pop();
        v.push_back(front->data);
        
        for(int i = 0; i < front->children.size(); i++){
            q.push(front->children[i]);
            v.push_back(front->children[i]->data);
        }
    }
    
    sort(v.begin(), v.end(), greater<int>());
    int ans = INT_MIN;
    int greatest = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i]!=greatest){
            ans = v[i];
            break;
        }
    }
    
    TreeNode<int>*ansNode =new TreeNode<int>(ans);
    return ansNode;
}


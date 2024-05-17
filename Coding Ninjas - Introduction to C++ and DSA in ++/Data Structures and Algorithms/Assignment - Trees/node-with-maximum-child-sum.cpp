
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

#include<bits/stdc++.h>
template <typename T>

class MaxNode{
    public :
    int sum;
    TreeNode<T>*node;

    MaxNode(TreeNode<T>*node, int sum){
        this->node = node;
        this->sum = sum;
    }
};

MaxNode<int>* maxSumNode_helper(TreeNode<int>*root){

    if(!root){
        return new MaxNode<int>(NULL, INT_MIN);
    }

    int currSum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        currSum += root->children[i]->data;
    }

    MaxNode<int>*currAns = new MaxNode<int>(root, currSum);

    for(int i = 0; i < root->children.size(); i++){
        MaxNode<int>*tempAns = maxSumNode_helper(root->children[i]);
        if(tempAns->sum > currAns->sum) currAns = tempAns;
    }
    return currAns;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    return maxSumNode_helper(root)->node;

}
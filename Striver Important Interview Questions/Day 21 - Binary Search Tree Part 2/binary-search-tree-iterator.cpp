
// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void findInorder(TreeNode*root, vector<int>&inorder){
    if(!root) return;
    findInorder(root->left, inorder);
    inorder.push_back(root->val);
    findInorder(root->right, inorder);
}

class BSTIterator {
    vector<int> path;
    int i;
public:
    BSTIterator(TreeNode* root) {
        findInorder(root, path);
        i = -1;
    }
    
    int next() {
        i++;
        return path[i];
    }
    
    bool hasNext() {
        return i != path.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
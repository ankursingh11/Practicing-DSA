
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void solve(Node*root, vector<vector<int>>&ans, vector<int>&smallAns){
        
        if(!root) return;
        if(!root->left && !root->right){
            smallAns.push_back(root->data);
            ans.push_back(smallAns);
            smallAns.pop_back();
        }
        
        smallAns.push_back(root->data);
        solve(root->left, ans, smallAns);
        solve(root->right, ans, smallAns);
        smallAns.pop_back();
        return;
    }
  
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        vector<int> smallAns;
        solve(root, ans, smallAns);
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    
    void solve(Node* root, int K, int &i, int &ans){
        if(!root) return;
        
        solve(root->right, K, i, ans);
        i+=1;
        if(i == K){
            ans = root->data;
            return;
        }
        solve(root->left, K, i, ans);
        return;
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans = -1;
        if(!root) return ans;
        
        int i = 0;
        solve(root, K, i, ans);
        
        return ans;
    }
};
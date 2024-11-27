
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            Node*currNode = front.first;
            int level = front.second;
            
            if(mp.find(level) == mp.end()) mp[level] = currNode->data;
            
            if(currNode->left) q.push({currNode->left, level-1});
            if(currNode->right) q.push({currNode->right, level+1});
        }
        
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};

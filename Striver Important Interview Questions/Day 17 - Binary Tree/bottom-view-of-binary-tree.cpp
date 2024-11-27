
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            
            mp[level] = currNode->data;
            
            if(currNode->left) q.push({currNode->left, level-1});
            if(currNode->right) q.push({currNode->right, level+1});
        }
        
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};
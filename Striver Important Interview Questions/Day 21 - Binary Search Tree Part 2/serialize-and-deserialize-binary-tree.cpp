
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front) ans += to_string(front->val) + ",";
            if(!front) ans += "#,";

            if(front){
                q.push(front->left);
                q.push(front->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode*root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            getline(s, str, ',');
            if(str != "#"){
                TreeNode*leftNode = new TreeNode(stoi(str));
                front->left = leftNode;
                q.push(leftNode);
            }else front->left = NULL;

            getline(s, str, ',');
            if(str != "#"){
                TreeNode*rightNode = new TreeNode(stoi(str));
                front->right = rightNode;
                q.push(rightNode);
            }else front->right = NULL;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
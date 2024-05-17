
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node*prev = NULL;
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();

            if(!currNode){
                if(q.empty()) break;
                prev->next = NULL;
                q.push(NULL);
                prev = NULL;
                continue;
            }

            if(!prev) prev = currNode;
            else{
                prev->next = currNode;
                prev = currNode;
            }
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }

        prev->next = NULL;
        return root;
    }
};
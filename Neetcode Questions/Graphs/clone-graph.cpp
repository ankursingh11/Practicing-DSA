
// https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void dfs(Node* child, Node* parent, vector<Node*>&visited){
        visited[parent->val] = child;

        for(auto nbr : parent->neighbors){
            if(!visited[nbr->val]){
                Node* newNode = new Node(nbr->val);
                child->neighbors.push_back(newNode);
                dfs(newNode, nbr, visited);
            }else child->neighbors.push_back(visited[nbr->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        
        if(!node) return node;

        vector<Node*> visited(1000, NULL);

        Node*copy = new Node(node->val);
        visited[node->val] = copy;

        for(auto nbr : node->neighbors){
            if(!visited[nbr->val]){
                Node*newNode = new Node(nbr->val);
                copy->neighbors.push_back(newNode);
                dfs(newNode, nbr, visited);
            }else copy->neighbors.push_back(visited[nbr->val]);
        }

        return copy;
    }
};
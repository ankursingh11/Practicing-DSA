
// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node*nextNode = NULL;
        Node*curr = head;

        // creating duplicate nodes
        while(curr){
            nextNode = curr->next;
            Node*copyNode = new Node(curr->val);
            curr->next = copyNode;
            copyNode->next = nextNode;
            curr = nextNode;
        }

        // assiging random pointers to the created nodes
        curr = head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // segregating both the lists
        Node*copy = new Node(-1);
        Node*temp = copy;
        curr = head;
        nextNode = NULL;
        while(curr){
            nextNode = curr->next->next;
            temp->next = curr->next;
            temp = temp->next;
            curr->next = nextNode;
            curr = curr->next;
        }
        
        return copy->next;
    }
};
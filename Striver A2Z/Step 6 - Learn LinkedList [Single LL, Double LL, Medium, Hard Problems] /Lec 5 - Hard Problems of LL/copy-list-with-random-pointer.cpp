
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

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
        if(!head) return head;

        Node*curr = head, *fwd = NULL;
        while(curr){
            fwd = curr->next;
            Node* newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = fwd;
            curr = fwd;
        }

        curr = head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node*res = new Node(-1);
        Node*copy = res;
        curr = head;
        while(curr){
            fwd = curr->next->next;
            copy->next = curr->next;
            copy = copy->next;
            curr->next = fwd;
            curr = curr->next;
        }

        return res->next;
    }
};
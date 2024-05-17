
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
        Node*itr = head, *fwd = NULL;
        while(itr){
            fwd = itr->next;
            Node*newNode = new Node(itr->val);
            itr->next = newNode;
            newNode->next = fwd;
            itr = fwd;
        }

        itr = head;
        while(itr){
            if(itr->random) itr->next->random = itr->random->next;
            itr = itr->next->next;
        }

        Node*copy = new Node(0);
        Node*res = copy;
        itr = head;
        while(itr){
            fwd = itr->next->next;
            copy->next = itr->next;
            copy = copy->next;
            itr->next = fwd;
            itr = fwd;
        }

        return res->next;
    }
};
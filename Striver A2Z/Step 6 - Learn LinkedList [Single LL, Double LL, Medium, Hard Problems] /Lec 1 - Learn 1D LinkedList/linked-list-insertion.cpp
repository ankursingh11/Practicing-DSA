
// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        
        Node*newNode = new Node(x);
        if(!head) return newNode;
        
        Node*curr = head;
        while(curr->next) curr = curr->next;
        curr->next = newNode;
        return head;
    }
};
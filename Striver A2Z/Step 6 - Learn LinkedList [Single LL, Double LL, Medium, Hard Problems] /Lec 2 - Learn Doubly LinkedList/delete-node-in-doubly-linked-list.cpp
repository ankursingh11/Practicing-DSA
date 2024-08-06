
// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list


class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1) return head->next;
        int count = 1;
        Node *temp1 = head;
        while(count<x){
            temp1 = temp1 -> next;
            count ++;
        }
        temp1 -> prev -> next = temp1 -> next;
        if(temp1 -> next != NULL){
            temp1 -> next -> prev = temp1 -> prev;
        }
        return head;
    }
};
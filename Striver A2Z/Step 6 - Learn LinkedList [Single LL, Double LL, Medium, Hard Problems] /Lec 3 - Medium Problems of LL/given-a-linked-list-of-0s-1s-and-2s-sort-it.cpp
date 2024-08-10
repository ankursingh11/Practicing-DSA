
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(!head) return head;
        int count_0, count_1, count_2;
        count_0 = count_1 = count_2 = 0;
        Node*curr = head;
        while(curr){
            if(curr->data == 0) count_0++;
            if(curr->data == 1) count_1++;
            if(curr->data == 2) count_2++;
            curr = curr->next;
        }
        int i = 0;
        curr = head;
        
        while(i < count_0){
            curr->data = 0;
            curr = curr->next;
            i++;
        }
        i = 0;
        while(i < count_1){
            curr->data = 1;
            curr = curr->next;
            i++;
        }
        i = 0;
        while(i < count_2){
            curr->data = 2;
            curr = curr->next;
            i++;
        }
        return head;
    }
};
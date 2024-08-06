
// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        if(!head) return false;
        
        Node*curr = head;
        while(curr){
            if(curr->data == key) return true;
            curr = curr->next;
        }
        return false;
    }
};
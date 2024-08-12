
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
  Node*reverseLL(Node*head){
      if(!head || !head->next) return head;
      Node*newHead = reverseLL(head->next);
      head->next->next = head;
      head->next = NULL;
      return newHead;
  }
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(!head) return head;
        head = reverseLL(head);
        head->data += 1;
        Node*curr = head;
        Node*prev = NULL;
        int carry = 0;
        while(curr){
            curr->data += carry;
            carry = curr->data/10;
            if(!carry) break;
            int num = curr->data%10;
            curr->data = num;
            prev = curr;
            curr = curr->next;
        }
        if(carry > 0){
            Node*newNode = new Node(carry);
            prev->next = newNode;
        }
        head = reverseLL(head);
        return head;
    }
};
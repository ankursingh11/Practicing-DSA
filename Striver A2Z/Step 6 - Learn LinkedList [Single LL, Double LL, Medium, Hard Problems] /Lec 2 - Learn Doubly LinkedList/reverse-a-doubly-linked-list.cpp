
// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(!head) return head;
        Node*curr = head;
        while(curr){
            Node*temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            head = curr;
            curr = curr->prev;
        }
        return head;
    }
};
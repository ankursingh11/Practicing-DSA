
// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list


class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        if(!head) return head;
        Node*curr = head;
        Node*prev = head;
        while(curr->next){
            if(curr->data == curr->next->data) curr->next = curr->next->next;
            else{
                curr->next->prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int lengthLL(ListNode*head){
        if(!head) return 0;
        int len = 0;
        while(++len && head) head = head->next;
        return (len-1);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        int len = lengthLL(head);
        int posFromStarting = len - n;
        if(posFromStarting == 0) return head->next;
        ListNode *curr = head, *prev = head;
        while(posFromStarting--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
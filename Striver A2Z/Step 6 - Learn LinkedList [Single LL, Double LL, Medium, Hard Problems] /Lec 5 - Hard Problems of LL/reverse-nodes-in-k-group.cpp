
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
        int len = 0;
        if(!head) return len;
        while(++len && head) head = head->next;
        return (len-1);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return head;

        int currLen = lengthLL(head);
        if(currLen < k) return head;
        int count = k;
        ListNode*prev = NULL, *curr = head, *fwd = NULL;
        while(curr && count--){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        if(fwd) head->next = reverseKGroup(fwd, k);
        return prev;

    }
};
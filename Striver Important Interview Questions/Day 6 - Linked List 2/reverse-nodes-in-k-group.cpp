
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

    int lengthLL(ListNode*head){
        if(!head) return 0;
        int len = 0;
        while(++len && head) head = head->next;
        return (len-1);
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return head;

        int currLen = lengthLL(head);
        if(currLen < k) return head;

        ListNode*curr = head, *prev = NULL, *fwd = NULL;
        int currentCount = 0;
        while(curr && currentCount++ < k){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        if(curr) head->next = reverseKGroup(fwd, k);
        return prev;
    }
};
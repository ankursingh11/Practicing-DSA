
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

    ListNode*removeNthFromEnd(ListNode*head, int n, int &i){
        if(!head) return head;
        head->next = removeNthFromEnd(head->next, n, i);
        i+=1;
        if(i == n) return head->next;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int i = 0;
        return removeNthFromEnd(head, n, i);
    }
};
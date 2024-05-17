
// https://leetcode.com/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int len = 0;
        ListNode*curr = head;
        while(++len && curr->next) curr = curr->next;
        k = k%len;
        k = len - k;
        curr->next = head;
        while(k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
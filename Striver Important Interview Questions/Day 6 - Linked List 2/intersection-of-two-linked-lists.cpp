
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA && !headB) return NULL;

        ListNode*x = headA, *y = headB;
        while(true){
            if(x == y) return x;

            x = (x == NULL) ? headB : x->next;
            y = (y == NULL) ? headA : y->next;
        }

        return NULL;
    }
};
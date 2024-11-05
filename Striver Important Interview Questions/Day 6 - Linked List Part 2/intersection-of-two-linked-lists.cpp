
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
        
        auto nodeA = headA, nodeB = headB;
        while(true){
            if(nodeA == nodeB) return nodeA;
            nodeA = (nodeA == NULL) ? headB : nodeA->next;
            nodeB = (nodeB == NULL) ? headA : nodeB->next;
        }
        return NULL;
    }
};
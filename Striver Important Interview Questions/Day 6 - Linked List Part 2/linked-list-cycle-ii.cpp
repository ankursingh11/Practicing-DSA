
// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;

        auto slow = head, fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(!fast || !fast->next) return NULL;
            if(slow == fast) break;
        }
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
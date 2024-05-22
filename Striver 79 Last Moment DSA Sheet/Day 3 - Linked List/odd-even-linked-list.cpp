
// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;

        ListNode*odd_head = head, *odd_tail = head;
        ListNode*even_head = head->next;
        auto even_tail = even_head;
        head = head->next->next;
        while(head){
            odd_tail->next = head;
            odd_tail = odd_tail->next;
            head = head->next;
            if(head){
                even_tail->next = head;
                even_tail = even_tail->next;
                head = head->next;
            }
        }
        even_tail->next = NULL;
        odd_tail->next = even_head;
        return odd_head;
    }
};
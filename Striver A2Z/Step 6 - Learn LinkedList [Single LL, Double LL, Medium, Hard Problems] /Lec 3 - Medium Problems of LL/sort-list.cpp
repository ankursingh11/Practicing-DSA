
// https://leetcode.com/problems/sort-list/description/

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

    ListNode* merge(ListNode* head1, ListNode* head2) {
        
        if(!head1 && !head2) return NULL;
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode*head = NULL, *tail = NULL;

        if(head1->val <= head2->val){
            head = tail = head1;
            head1 = head1->next;
        }else{
            head = tail = head2;
            head2 = head2->next;
        }

        while(head1 && head2){
            if(head1->val <= head2->val){
                tail->next = head1;
                head1 = head1->next;
            }else{
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if(!head1) tail->next = head2;
        if(!head2) tail->next = head1;

        return head;
    }

    ListNode*findMid(ListNode*head){
        if(!head) return head;
        ListNode*slow = head, *fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*mid = findMid(head);
        ListNode*head2 = mid->next, *head1 = head;
        mid->next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
};
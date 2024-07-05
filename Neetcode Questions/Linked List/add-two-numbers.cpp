
// https://leetcode.com/problems/add-two-numbers/

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(l1 && !l2) return l1;
        if(!l1 && l2) return l2;

        ListNode*head = NULL, *tail = NULL;
        int carry = 0;

        while(l1 && l2){
            int curr = l1->val + l2->val + carry;
            carry = curr/10;
            curr = curr%10;
            ListNode*newNode = new ListNode(curr);
            if(!head) head = tail = newNode;
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int curr = l1->val + carry;
            carry = curr/10;
            curr = curr%10;
            ListNode*newNode = new ListNode(curr);
            tail->next = newNode;
            tail = newNode;
            l1 = l1->next;
        }

        while(l2){
            int curr = l2->val + carry;
            carry = curr/10;
            curr = curr%10;
            ListNode*newNode = new ListNode(curr);
            tail->next = newNode;
            tail = newNode;
            l2 = l2->next;
        }

        if(carry > 0){
            // carry = carry/10;
            ListNode*newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }

        tail->next = NULL;

        // head = reverseLL(head);
        return head;
    }
};
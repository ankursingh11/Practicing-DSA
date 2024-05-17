
// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(list1 && !list2) return list1;
        if(!list1 && list2) return list2;

        ListNode*head = NULL, *tail = NULL;

        if(list1->val <= list2->val){
            head = tail = list1;
            list1 = list1->next; 
        }else{
            head = tail = list2;
            list2 = list2->next;
        }

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if(!list1) tail->next = list2;
        if(!list2) tail->next = list1;

        return head;
    }
};
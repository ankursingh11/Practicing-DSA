
// https://leetcode.com/problems/reorder-list/description/

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
    void reorderList(ListNode* head) {
        if(!head) return;

        vector<int> arr;
        ListNode*temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        int i = 0, j = arr.size()-1;
        for( ; i < j; i++, j--){
            temp->val = arr[i];
            temp = temp->next;
            temp->val = arr[j];
            temp = temp->next;
        }

        if(i == j) temp->val = arr[i];
        return;
    }
};
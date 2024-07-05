
// https://leetcode.com/problems//description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*head = NULL, *tail = NULL;
        int size = lists.size();
        if(size == 0) return head;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto currHead : lists){
            while(currHead){
                pq.push(currHead->val);
                currHead = currHead->next;
            }
        }

        while(!pq.empty()){
            ListNode*newNode = new ListNode(pq.top());
            pq.pop();
            if(!head) head = tail = newNode;
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};
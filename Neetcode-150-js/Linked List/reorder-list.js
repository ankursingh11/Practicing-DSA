
// https://leetcode.com/problems/reorder-list/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if(!head || !head.next) return head;

    const arr = [];
    let temp = head;
    while(temp){
        arr.push(temp.val);
        temp = temp.next;
    }
    
    temp = head;
    let i = 0, j = arr.length-1;
    while(i <= j){
        temp.val = arr[i++];
        temp = temp.next;
        if(temp){
            temp.val = arr[j--];
            temp = temp.next;
        }
    }
    return head;
};
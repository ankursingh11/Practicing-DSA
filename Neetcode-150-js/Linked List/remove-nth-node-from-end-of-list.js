
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */

let i = 0;

var helper = function(head, n){
    if(!head) return head;
    head.next  = removeNthFromEnd(head.next, n);
    i++;
    if(i === n) return head.next;
    return head;
}

var removeNthFromEnd = function(head, n) {
    if(!head) return head;
    i = 0;
    return helper(head, n);
};



// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

var lengthLL = function(head){
    let length = 0;
    if(!head) return length;
    while(head){
        head = head.next;
        length++;
    }
    return length;
}

var reverseKGroup = function(head, k) {
    if(!head || k === 0) return head;
    let length = lengthLL(head);
    if(length < k) return head;

    let curr = head, fwd = null, prev = null;
    let count = 0;
    while(curr && count < k){
        fwd = curr.next;
        curr.next = prev;
        prev = curr;
        curr = fwd;
        count++;
    }

    if(fwd) head.next = reverseKGroup(curr, k);
    return prev;
};
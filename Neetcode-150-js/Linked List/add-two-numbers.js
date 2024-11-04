
// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(!l1 && !l2) return null;

    let carry = 0;
    let head = null;
    let tail = null;

    while(l1 || l2 || carry){
        let val1 = l1 ? l1.val : 0;
        let val2 = l2 ? l2.val : 0;
        
        let currSum = val1 + val2 + carry;
        let num = currSum%10;
        carry = Math.floor(currSum/10);
        let newNode = new ListNode(num);
        if(!head){
            head = newNode;
            tail = newNode;
        } else{
            tail.next = newNode;
            tail = tail.next;
        }
        if(l1) l1 = l1.next;
        if(l2) l2 = l2.next;
    }

    return head;
};
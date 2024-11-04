
// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

var mergeTwoLists = function(head1, head2) {

    if(!head1) return head2;
    if(!head2) return head1;

    let newHead;
    let tail;

    if(head1.val <= head2.val){
        newHead = head1;
        head1 = head1.next;
    }else{
        newHead = head2;
        head2 = head2.next; 
    }
    tail = newHead;

    while(head1 && head2){
        if(head1.val <= head2.val){
            tail.next = head1;
            head1 = head1.next
        }else{
            tail.next = head2;
            head2 = head2.next;
        }
        tail = tail.next;
    }

    tail.next = (head1) ? head1 : head2;

    return newHead;  
};

var mergeKLists = function(lists) {
    
    let len = lists.length;
    if(len === 0) return null;

    let newHead = lists[0];
    
    for(let i = 1; i < len; i++){
        newHead = mergeTwoLists(newHead, lists[i]);
    }

    return newHead;
};
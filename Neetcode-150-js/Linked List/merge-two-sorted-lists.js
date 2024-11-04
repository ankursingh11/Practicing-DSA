
// https://leetcode.com/problems/merge-two-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    if(!list1) return list2;
    if(!list2) return list1;
    if(!list1 && !list2) return null;

    let head = new ListNode();
    let tail = new ListNode();

    if(list1.val <= list2.val){
        head = list1;
        list1 = list1.next;
    }else{
        head = list2;
        list2 = list2.next;
    }
    tail = head;

    while(list1 && list2){
        if(list1.val <= list2.val){
            tail.next = list1;
            list1 = list1.next;
        }else{
            tail.next = list2;
            list2 = list2.next;
        }
        tail = tail.next;
    }

    if(!list1) tail.next = list2;
    if(!list2) tail.next = list1;

    // tail.next = null;
    return head;
};
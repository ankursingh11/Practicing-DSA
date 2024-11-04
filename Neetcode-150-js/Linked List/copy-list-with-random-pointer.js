
// https://leetcode.com/problems/copy-list-with-random-pointer/

/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function(head) {

    // base case
    if(!head) return head;

    let temp = head;
    while(temp){
        let copyNode = new Node(temp.val);
        let nextNode = temp.next;
        temp.next = copyNode;
        copyNode.next = nextNode;
        temp = temp.next.next;
    }

    temp = head;
    while(temp){
        if(temp.random) temp.next.random = temp.random.next;
        temp = temp.next.next;
    }

    let copyHead = new Node(null, null, null);
    let copyTemp = copyHead;
    temp = head;
    while(temp){
        let nextNode = temp.next.next;
        copyTemp.next = temp.next;
        copyTemp = copyTemp.next
        temp.next = nextNode;
        temp = temp.next;
    }

    return copyHead.next;
};
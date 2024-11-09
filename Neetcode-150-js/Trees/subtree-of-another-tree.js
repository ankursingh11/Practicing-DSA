
// https://leetcode.com/problems/subtree-of-another-tree/description/

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} subRoot
 * @return {boolean}
 */

var isSame = function(p, q){
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p.val !== q.val) return false;
    return isSame(p.left, q.left) && isSame(p.right, q.right);
}


var isSubtree = function(root, subRoot) {
    if(!root) return false;
    if(root.val === subRoot.val){
        if(isSame(root, subRoot)) return true;
    }
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
};
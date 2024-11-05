
// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
 * @return {number}
 */

var height = function(root){
    if(!root) return 0;
    return 1 + Math.max(height(root.left), height(root.right));
}

var diameterOfBinaryTree = function(root) {
    if(!root) return 0;
    let h = height(root.left) + height(root.right);
    let ld = diameterOfBinaryTree(root.left);
    let rd = diameterOfBinaryTree(root.right);
    return Math.max(h, ld, rd);
};
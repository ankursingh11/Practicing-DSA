
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
 * @return {number[]}
 */
var solve = (root, inorder) => {
    if(!root) return;
    solve(root.left, inorder);
    inorder.push(root.val);
    solve(root.right, inorder);
    return;
}

var inorderTraversal = function(root) {
    const inorder = [];
    if(!root) return inorder;
    solve(root, inorder);
    return inorder;
};
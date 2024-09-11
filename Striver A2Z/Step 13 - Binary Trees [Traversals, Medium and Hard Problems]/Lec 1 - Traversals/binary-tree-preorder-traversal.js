
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// const preorder = [];

var solve = (root, preorder) => {
    if(!root) return;
    preorder.push(root.val);
    solve(root.left, preorder);
    solve(root.right, preorder);
    return; 
}

var preorderTraversal = function(root) {
    const preorder = [];
    if(!root) return preorder;
    solve(root, preorder);
    return preorder;
};

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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

var solve = (root, postorder) => {
    if(!root) return;
    solve(root.left, postorder);
    solve(root.right, postorder);
    postorder.push(root.val);
    return;
}

var postorderTraversal = function(root) {
    const postorder = [];
    if(!root) return postorder;
    solve(root, postorder);
    return postorder;
};
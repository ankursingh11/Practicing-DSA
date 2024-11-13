
// https://leetcode.com/problems/validate-binary-search-tree/description/

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
 * @return {boolean}
 */
var isValidBST = function(root) {
    if(!root) return true;

    var solve = (root, minNode, maxNode) => {
        if(!root) return true;
        if(root.val <= minNode || root.val >= maxNode) return false;
        return solve(root.left, minNode, root.val) && solve(root.right, root.val, maxNode);
    }

    return solve(root, Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
};
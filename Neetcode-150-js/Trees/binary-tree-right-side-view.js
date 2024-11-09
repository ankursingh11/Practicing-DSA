
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
var rightSideView = function(root) {
    const ans = [];
    let level = 0;

    var solve = function(root, ans, level){
        if(!root) return;
        if(level === ans.length) ans.push(root.val);
        solve(root.right, ans, level+1);
        solve(root.left, ans, level+1);
    }

    solve(root, ans, level);
    return ans;
};
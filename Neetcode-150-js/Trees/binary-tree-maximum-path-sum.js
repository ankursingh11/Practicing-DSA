
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
var maxPathSum = function(root) {
    if(!root) return 0;
    let maxValue = Number.MIN_SAFE_INTEGER;
  
    var check = (root) => {
      if(!root) return 0;
      let leftAns = Math.max(check(root.left), 0);
      let rightAns = Math.max(check(root.right), 0);
      maxValue = Math.max(maxValue, root.val + leftAns + rightAns);
      return root.val + Math.max(leftAns, rightAns);
    } 
  
      check(root);
      return maxValue;
  };
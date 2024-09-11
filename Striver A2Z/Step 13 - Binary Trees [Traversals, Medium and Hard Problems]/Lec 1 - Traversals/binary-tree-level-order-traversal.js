// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
 * @return {number[][]}
 */
var levelOrder = function (root) {
  const ans = [];
  if (!root) return ans;

  const q = [root, null];
  let smallAns = [];
  while (!(q.length === 0)) {
    let front = q.shift();

    if (!front) {
      if (q.length === 0) break;
      ans.push(smallAns);
      smallAns = [];
      q.push(null);
      continue;
    }

    smallAns.push(front.val);
    if (front.left) q.push(front.left);
    if (front.right) q.push(front.right);
  }

  ans.push(smallAns);
  return ans;
};

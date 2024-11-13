
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let ans = -1;
    if(!root) return ans;
    let count = 0;
    
    var solve = (root) => {
        if(!root) return;

        // if(count === k){
        //     ans = root.val;
        //     return;
        // }
        solve(root.left);
        count++;
        if(count === k){
            ans = root.val;
            return;
        }
        solve(root.right);
        return;
    }

    solve(root);
    return ans;
};
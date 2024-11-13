
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
var goodNodes = function(root) {
    if(!root) return 0;
    let goodNodes = 1;
    const path = [];
    path.push(root.val);

    function solve(root){
        if(!root) return;

        path.push(root.val);

        // checking for whether the node pushed is good or not ?
        var check = () =>  {
            let val = path[path.length-1];
            let flag = true;
            for(let i = path.length-2; i >= 0; i--){
                if(path[i] > val){
                    flag = false;
                    break;
                }
            }
            if(flag) goodNodes++;
        }

        check();
        solve(root.left);
        solve(root.right);
        path.pop();
        return;
    }

    solve(root);
    return goodNodes-1;
};
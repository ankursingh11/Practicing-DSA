
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Definition for a binary tree node.
class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class Solution {
  solve(preorder, preS, preE, inorder, inS, inE) {
    if (preS > preE || inS > inE) return null;

    const rootData = preorder[preS];
    let rootIndex = -1;
    for (let i = 0; i < inorder.length; i++) {
      if (inorder[i] === rootData) {
        rootIndex = i;
        break;
      }
    }

    const LinS = inS;
    const LinE = rootIndex - 1;
    const RinS = rootIndex + 1;
    const RinE = inE;

    const LpreS = preS + 1;
    const LpreE = LinE - LinS + LpreS;
    const RpreS = LpreE + 1;
    const RpreE = preE;

    const root = new TreeNode(rootData);

    root.left = this.solve(preorder, LpreS, LpreE, inorder, LinS, LinE);
    root.right = this.solve(preorder, RpreS, RpreE, inorder, RinS, RinE);
    return root;
  }

  buildTree(preorder, inorder) {
    if (preorder.length === 0 || inorder.length === 0) return null;

    return this.solve(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
  }
}


// https://www.naukri.com/code360/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    if(!root) return ans;

    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    vector<int> preorder, inorder, postorder;
    while(!st.empty()){
        auto top = st.top();
        st.pop();
        int level = top.second;
        TreeNode* curr = top.first;

        // preorder
        if(level == 1){
            preorder.push_back(curr->data);
            level++;
            st.push({curr, level});
            if(curr->left) st.push({curr->left, 1});
        }
        // inorder
        else if(level == 2){
            inorder.push_back(curr->data);
            level++;
            st.push({curr, level});
            if(curr->right) st.push({curr->right, 1});
        }
        // postorder
        else postorder.push_back(curr->data);
    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
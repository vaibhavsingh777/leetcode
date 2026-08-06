/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == nullptr) return preorder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
    TreeNode* curr = st.top(); // Grab the node
    st.pop();                  // Remove it from the waiting list
    
    preorder.emplace_back(curr->val); // Use the node
    
    if(curr->right != nullptr){
        st.push(curr->right);
    }
    if(curr->left != nullptr){
        st.push(curr->left);
    }
}
        return preorder;
    }
};
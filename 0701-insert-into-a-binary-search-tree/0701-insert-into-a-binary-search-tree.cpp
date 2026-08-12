class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: we found the empty spot, return the new node
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        // If the value is less, we must go left
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } 
        // If the value is greater, we must go right
        else {
            root->right = insertIntoBST(root->right, val);
        }
        
        // Return the unchanged root pointer
        return root;
    }
};
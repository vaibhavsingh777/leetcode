class Solution {
private:
  
    void traverse(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return; 
        }
        result.push_back(root->val);
        traverse(root->left, result);
        traverse(root->right, result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        traverse(root, result); 
        return result; 
    }
};
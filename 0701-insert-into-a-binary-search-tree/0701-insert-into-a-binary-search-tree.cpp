class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;
while(1){
        if(val < curr->val){
            if(curr->left == nullptr)
            {
                curr->left = new TreeNode(val);
                break;
            }
            else curr = curr->left;
        }
        else {
            if(curr->right == nullptr)
            {
                curr->right = new TreeNode(val);
                break;
            }
            else curr = curr->right;
        }
}
        return root;
    }
};
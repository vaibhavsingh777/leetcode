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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else {
            //case 1,2 no child or 1 child
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root; 
                return temp;
            }
            //case 3 two children
            else {
                TreeNode* curr = root->right;
                while(curr->left != nullptr)
                {
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};
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
private:
    // Initialize to the lowest possible integer because the max sum could be negative!
    int max_sum = INT_MIN; 
    
    int getGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        //postorder traversal
        int left_gain = max(0, getGain(node->left));
        int right_gain = max(0, getGain(node->right));
        
     
        int current_path_sum = node->val + left_gain + right_gain;
        max_sum = max(max_sum, current_path_sum);
        
        
        return node->val + max(left_gain, right_gain);
    }

public:
    int maxPathSum(TreeNode* root) {
        getGain(root);
        return max_sum;
    }
};
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

pair<int,int> dfs(TreeNode* node){
    if(!node) return {0,0};

    auto left = dfs(node->left);
    auto right = dfs(node->right);

    int rob = node->val + left.second + right.second;
    int not_rob = max(left.first, left.second) + max(right.first, right.second);

    return {rob, not_rob};
}
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
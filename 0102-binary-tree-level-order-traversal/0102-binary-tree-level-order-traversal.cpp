class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return {};
        
        // FIX: Use angle brackets for the type, and name the variable 'q'
        queue<TreeNode*> q; 
        
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                
                level.emplace_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
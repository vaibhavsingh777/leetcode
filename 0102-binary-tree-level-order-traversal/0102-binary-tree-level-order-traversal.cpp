class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res; // 1. Guard against null root

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levsize = q.size();
            vector<int> curlevel; // 2. Declare outside inner loop

            for (int i = 0; i < levsize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                curlevel.push_back(curr->val); // 3. Push integer value

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(curlevel); // 4. Add the completed level
        }
        return res;
    }
};
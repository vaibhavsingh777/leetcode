class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int diff = i - j;
                mp[diff].emplace_back(mat[i][j]);
            }
        }

        for(auto& pair : mp){
            sort(pair.second.rbegin(), pair.second.rend());
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = mp[i - j].back();
                mp[i-j].pop_back();
        }
        }
        return mat;

    }
};
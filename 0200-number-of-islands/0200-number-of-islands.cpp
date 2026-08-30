class Solution {
private:
void dfs(const vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis, int n, int m){
if(i<0 || j<0 || i>=n || j>= m || vis[i][j] || grid[i][j] == '0' ) return;
vis[i][j] = true;

dfs(grid, i - 1, j, vis, n, m);
dfs(grid, i, j + 1, vis, n, m);
dfs(grid, i + 1, j, vis, n, m);
dfs(grid, i, j - 1, vis, n, m);


}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, vis, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base case: out of bounds or water
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        // Mark as visited by sinking the island
        grid[r][c] = 0;

        // Count this cell (1) + area from all 4 directions
        return 1 + dfs(grid, r + 1, c)
                 + dfs(grid, r - 1, c)
                 + dfs(grid, r, c + 1)
                 + dfs(grid, r, c - 1);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Whenever we find land, compute its area and update maxArea
                if (grid[r][c] == 1) {
                    int currentArea = dfs(grid, r, c);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }


};
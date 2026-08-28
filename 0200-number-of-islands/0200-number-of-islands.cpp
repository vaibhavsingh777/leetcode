#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<char>>& grid, int n, int m) {
        // Base case: Check out-of-bounds, already visited, or water ('0')
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') {
            return;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Recursively visit all 4 neighbors (Top, Right, Bottom, Left)
        dfs(i - 1, j, visited, grid, n, m); // Top
        dfs(i, j + 1, visited, grid, n, m); // Right
        dfs(i + 1, j, visited, grid, n, m); // Bottom
        dfs(i, j - 1, visited, grid, n, m); // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;
        
        // Iterate through every cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If we find an unvisited land cell ('1'), it's a new island component
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandCount++;
                    // DFS will explore and mark all connected land cells of this island
                    dfs(i, j, visited, grid, n, m);
                }
            }
        }
        
        return islandCount;
    }
};
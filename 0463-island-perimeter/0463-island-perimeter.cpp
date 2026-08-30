class Solution {
private: 
    int perichecker(const vector<vector<int>>& grid, int i, int j, int m, int n) {
        int edges = 0;

        // Top: boundary or water contributes 1 edge
        if (i == 0 || grid[i - 1][j] == 0) edges++;
        // Bottom: boundary or water contributes 1 edge
        if (i == m - 1 || grid[i + 1][j] == 0) edges++;
        // Left: boundary or water contributes 1 edge
        if (j == 0 || grid[i][j - 1] == 0) edges++;
        // Right: boundary or water contributes 1 edge
        if (j == n - 1 || grid[i][j + 1] == 0) edges++;

        return edges;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();       // rows
        int n = grid[0].size();    // columns
        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    perimeter += perichecker(grid, i, j, m, n);
                }
            }
        }
        return perimeter;
    }
};
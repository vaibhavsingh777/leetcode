class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> dp(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++){
            dp[i][0] = true;
        }
        int max_moves = 0;
        // Process column by column, starting from Col 1
        for (int c = 1; c < n; c++) {
            bool can_reach_this_col = false;
            
            for (int r = 0; r < m; r++) {
                
                // Check Right-Down from the row above (r-1)
                if (r > 0 && dp[r-1][c-1] && grid[r][c] > grid[r-1][c-1]) {
                    dp[r][c] = true;
                }
                // Check Straight-Right from the same row (r)
                if (dp[r][c-1] && grid[r][c] > grid[r][c-1]) {
                    dp[r][c] = true;
                }
                // Check Right-Up from the row below (r+1)
                if (r < m - 1 && dp[r+1][c-1] && grid[r][c] > grid[r+1][c-1]) {
                    dp[r][c] = true;
                }
                
                // If we reached this cell, we know we can at least make 'c' moves
                if (dp[r][c]) {
                    can_reach_this_col = true;
                    max_moves = max(max_moves, c);
                }
            }
            
            // Early Exit Optimization: 
            // If an entire column is unreachable, we can't possibly reach any columns after it.
            if (!can_reach_this_col) {
                break;
            }
        }
        
        return max_moves;
    }
};
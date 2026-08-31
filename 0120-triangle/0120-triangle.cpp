class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Create a DP table of the exact same shape as the triangle
        vector<vector<int>> dp = triangle;
        
        // Start from the second-to-last row and build upwards
        for(int i = n - 2; i >= 0; i--) {
            // Number of elements in row i is i + 1
            for(int j = 0; j <= i; j++) {
                // The minimum cost to reach the bottom from the current cell 
                // is its own value + the cheaper of the two paths below it
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        // The top element now holds the minimum path sum for the whole triangle
        return dp[0][0];
    }
};
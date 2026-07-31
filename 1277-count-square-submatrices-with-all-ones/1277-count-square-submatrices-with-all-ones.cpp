class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==0) return 0;
        int totalSquares = 0;

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1 && i > 0 && j > 0)
                {
                    // Update the cell to represent the max square ending here
                    matrix[i][j] = min({matrix[i-1][j],    // Top
                                        matrix[i][j-1],    // Left
                                        matrix[i-1][j-1]   // Top-Left
                                       }) + 1;
                }
                // Add the count of squares ending at (i, j) to our total
                // Note: If matrix[i][j] was originally 0, it stays 0, adding nothing.
                totalSquares += matrix[i][j];
            }
        }
        return totalSquares;
    }
};
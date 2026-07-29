class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //simple solution
        //transpose the matrix and reverse each row

        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
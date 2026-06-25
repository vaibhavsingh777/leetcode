class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows * cols - 1;

        while(left <= right){
            int mid = left + (- left + right)/2;
            int row = mid / cols;
            int col = mid % cols;
            int guess = matrix[row][col];

            if(guess == target) return 1;
            else if(guess < target)
            {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return 0;
    }
};
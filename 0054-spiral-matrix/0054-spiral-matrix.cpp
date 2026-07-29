class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top = 0; 
        int bottom = m - 1;
        int left = 0; 
        int right = n - 1;
        //traversing left to right first
        while (top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            result.emplace_back(matrix[top][i]);
        }
        top++;
        //traversing top to bottom now
        for(int j = top; j <= bottom; j++){
            result.emplace_back(matrix[j][right]);
        }
        right--;
        //traversing r2l first
        if(top <= bottom){
        for(int i = right; i >= left; i--){
            result.emplace_back(matrix[bottom][i]);
        }
        bottom--;
        }
        //traversing b2t now
        if(left <= right){
        for(int j = bottom; j >= top; j--){
            result.emplace_back(matrix[j][left]);
        }
        left++;
        }
        }
        return result;
    }
};
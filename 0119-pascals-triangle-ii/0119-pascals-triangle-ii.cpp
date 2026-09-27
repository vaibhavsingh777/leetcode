class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1); // The first element is always 1
        
        long long prev = 1; // Use long long to prevent overflow during multiplication
        
        for(int i = 1; i <= rowIndex; i++){
            // Calculate the next element based on the previous one
            long long curr = prev * (rowIndex - i + 1) / i;
            result.push_back(curr);
            prev = curr;
        }
        
        return result;
    }
};
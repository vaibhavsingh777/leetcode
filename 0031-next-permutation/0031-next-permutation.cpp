class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        
        // Step 1: Find the first element from right that decreases
        for(int i = n-2; i>=0;i--){
            if(nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        //If no pivot is found then the array is in strict descending order,
        //so just reverse the array
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the element from right strictly greater than pivot
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        //reverse starting from pivot
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
};
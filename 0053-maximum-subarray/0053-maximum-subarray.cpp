class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //we can either stop and start new subarray greater than
        //total sum till now or keep adding to prev sum
        int n = nums.size();
        int ms = nums[0], cs = nums[0];
        for(int i = 1; i < n; i++){
            cs = max(nums[i], cs + nums[i]);
            ms = max(cs,ms);
        }
        return ms;

    }
};
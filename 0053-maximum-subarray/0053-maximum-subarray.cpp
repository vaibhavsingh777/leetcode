class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curMax = nums[0];
        int globMax = curMax;

        for(int i = 1;i < n;i++){
            curMax = max(nums[i], curMax + nums[i]);
            globMax = max(globMax, curMax);
        }
        return globMax;
    }
};
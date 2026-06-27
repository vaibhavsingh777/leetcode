class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int curMax = nums[0];
        int globMax = curMax;
        for(int i = 1; i < n;i++){
            curMax = max(curMax + nums[i], nums[i]);
            globMax = max(curMax, globMax);
        }
        return globMax;
    }
};
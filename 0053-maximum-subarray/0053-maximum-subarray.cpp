class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax = nums[0];
        int globmax = curmax;
        for(int i = 1; i < nums.size(); ++i){
            curmax = max(nums[i], nums[i] + curmax);
            globmax = max(globmax, curmax);
        }
        return globmax;

        
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        int curMax = nums[0];
        int curMin = nums[0];
        int globMax = curMax;

        for(int i = 1; i < nums.size(); i++){

            int tempMax = curMax;
            // Choice 1: Start fresh from nums[i]
            // Choice 2: Extend the previous max
            // Choice 3: The "Negative Flip" (extending the previous min)
            curMax = max({nums[i], tempMax * nums[i], curMin * nums[i]});
            curMin = min({nums[i], tempMax * nums[i], curMin * nums[i]});
            globMax = max(globMax, curMax);
        }
        return globMax;
    }
};
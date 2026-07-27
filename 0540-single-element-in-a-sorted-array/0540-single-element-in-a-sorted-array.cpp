class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = 1;
        if (nums.size() == 1) return nums[0];
        while(nums[low] == nums[high] && high < nums.size()){
            low+=2, high+=2;
        }
        return nums[low];
    }
};
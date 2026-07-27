class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                int left = mid;
                int right = mid;

                while(left >= 0 && nums[left] == target)
                {
                    left--;
                }
                while(right < nums.size() && nums[right] == target)
                {
                    right++;
                }
                return {left+1, right-1};
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};
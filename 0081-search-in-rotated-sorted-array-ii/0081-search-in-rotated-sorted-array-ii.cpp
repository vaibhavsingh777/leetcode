class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            //identify which side is sorted
            //left side is sorted
            if(nums[mid] == target) return 1;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
              low++, high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid])
                {
                   high = mid - 1;
                }
                else low = mid + 1;
            }
            
            else {
                if(nums[mid] < target && target <= nums[high])
                {
                   low = mid + 1;
                }
                else high = mid - 1;
            }
        }
       
        return false;
    }
};

/*Two changes:

nums[low] <= target (was <) — since target could equal nums[low] and we still need to search left.
target <= nums[high] (was <) — same reasoning for the right side.*/
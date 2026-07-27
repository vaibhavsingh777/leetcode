class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make sure mid is even so we can compare it with mid + 1
            if (mid % 2 == 1) {
                mid--;
            }

            // If mid and mid + 1 match, the pattern hasn't broken yet.
            // The single element must be on the right side.
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                // Otherwise, the pattern broke, so the single element is at mid or to the left.
                high = mid;
            }
        }

        return nums[low];
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        // We only need to iterate up to n - 2 to leave room for left and right pointers
        for (int i = 0; i < n - 2; ++i) {
            
            // OPTIMIZATION 1: Early termination
            // If the smallest number is positive, it's impossible to sum to 0
            if (nums[i] > 0) {
                break;
            }
            
            // Skip duplicates for our base number 'i'
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move both pointers inward after finding a valid triplet
                    ++left;
                    --right;

                    // OPTIMIZATION 2: Skip duplicates for both inner pointers
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
            }
        }
        return res;        
    }
};
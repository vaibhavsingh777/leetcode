class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> totals;

      for(int i = 0; i < nums.size();i++){
        int complement = target - nums[i];

        if(totals.count(complement))
        {
            return {totals[complement], i};
        }
        
        totals[nums[i]] = i;
      }
              return {};
    }
};
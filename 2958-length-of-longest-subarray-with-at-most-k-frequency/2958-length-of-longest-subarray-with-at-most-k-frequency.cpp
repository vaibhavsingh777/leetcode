class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int left = 0, right = 0, maxLength = 0;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++;
            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
        int currentLength = right - left + 1;
        maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};
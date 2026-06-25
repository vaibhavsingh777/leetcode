class Solution {
private:
    int robbery(vector<int>& nums, int start, int end) {
        int n = end - start;
        vector <int> dp(n);

        if (n == 0) return 0;
        if (n == 1) return nums[0];

       int prev2 = nums[start];
       int prev = max(nums[start], nums[start+1]);

        for(int i = start + 2; i < end; i++){
          int curi = max(nums[i] + prev2, prev);
          prev2 = prev;
          prev = curi;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int temp1, temp2;
        temp1 = robbery(nums, 0, n-1);
        temp2 = robbery(nums, 1, n);

        return max(temp1,temp2);
    }
};
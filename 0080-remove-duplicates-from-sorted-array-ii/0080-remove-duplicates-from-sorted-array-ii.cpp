class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int l = 2;
        for(int r = 2; r <n; r++){
            if(nums[r] != nums[l-2]){
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
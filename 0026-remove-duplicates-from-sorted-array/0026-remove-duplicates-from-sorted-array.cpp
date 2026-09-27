class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int b = 0;

        for(int f = 1; f < n; f++){
            if(nums[f] != nums[b]){
                nums[++b] = nums[f];
            }
        }
        return b+1;
    }
};
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
       //edge case start
       if(n == 1) return 0;
       else if(nums[0] > nums[1]) return 0;
       else if(nums[n-1] > nums[n-2]) return n-1;
       //edge case end

       else{
       for(int i = 1; i < nums.size()-1; i++){
        if(nums[i] > nums[i+1] && nums[i] > nums[i-1])
        {
            return i;   
        }
       }
       }
       
       return 0;
    }
};
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(nums[mid] < nums[mid+1])// Slope goes UP to the right -> Walk right
            {
                low = mid+1;
            }
            else high = mid;
        }
        return low;
    }
};
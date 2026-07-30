class Solution {
private:
int calcSum(const vector<int>& nums, int divisor){
int sum = 0;
for(int num : nums){
    sum += (num + divisor - 1)/divisor;
}
return sum;
}

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(calcSum(nums, mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
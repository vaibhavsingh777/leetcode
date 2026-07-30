class Solution {
private:
    // Helper function: Calculates how many days are needed for a given ship capacity
    int getDaysNeeded(const vector<int>& weights, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;   // Start a new day
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return daysNeeded;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i : weights){
            high += i;
        }
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(getDaysNeeded(weights, mid) <= days)
            {
                ans = mid;
                high = mid-1;    
            }
            else low = mid + 1;
        }
        return ans;
    }
};
class Solution {
private:
    // Helper function: Calculates how many days are needed for a given ship capacity
   int getDaysNeeded(const vector<int>& weights, int capacity) {
    int daysNeeded = 1;   // Start with Day 1
    int currentLoad = 0;  // Weight loaded on the current day

    for (int w : weights) {
        // Can we add this package to today's load?
        if (currentLoad + w > capacity) {
            daysNeeded++; // No! Send today's ship out, start a NEW day
            currentLoad = w; // Put this package as the FIRST item on the new day
        } else {
            currentLoad += w; // Yes! Add it to today's load
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
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int maxi = *max_element(piles.begin(), piles.end());
        int high = maxi;

        while(low <= high){
            int mid = low +(high - low)/2;
            long long hours = 0;

            for(int i = 0; i < n;i++){
                hours += (piles[i] + mid - 1) / mid; //ceiling
            }
                if(hours <= h)
                {
                   high = mid - 1;
                } 
                else low = mid + 1;
            
        }
        return low;
    }
};
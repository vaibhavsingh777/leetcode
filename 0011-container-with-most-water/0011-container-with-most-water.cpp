class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxi = 0;

        while(low < high){
            if(height[low] > height[high])
            {
                int volume = (height[high] * (high - low));
                maxi = max(volume,maxi);
                high--;
            }
            else{
                int volume = (height[low] * (high - low));
                maxi = max(volume,maxi);
                low++;
            }
        }
        return maxi;
    }
};
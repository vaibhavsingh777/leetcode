class Solution {
public:
    int trap(vector<int>& height) {
        //main formula for water calculation at each index
        int left = 0, right = height.size() - 1, leftMax = height[left], rightMax = height[right], water = 0;

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(height[left], leftMax);
                water += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }
        return water;
    }
};
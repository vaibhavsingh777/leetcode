class Solution {
public:
    int trap(vector<int>& height) {
       int left = 0;
       int right = height.size() - 1;
       int leftMax = height[left];
       int rightMax = height[right];
       int water = 0;

       while(left < right){
        if(leftMax < rightMax){
            left++;
            leftMax = max(height[left], leftMax);
            water += leftMax - height[left];
        }
        else {
            right--;
            rightMax = max(height[right], rightMax);
            water += rightMax - height[right];
        }
       } 
       return water;
    }
};
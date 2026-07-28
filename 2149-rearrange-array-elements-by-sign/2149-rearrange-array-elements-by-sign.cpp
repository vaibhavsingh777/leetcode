class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,0);
        int posIndex = 0;
        int negIndex = 1;
        for(auto num : nums){
          if(num > 0){
            answer[posIndex] = num;
            posIndex+=2;
          }
          else {
            answer[negIndex] = num;
            negIndex+=2;
          }
        }
        return answer;
    }
};
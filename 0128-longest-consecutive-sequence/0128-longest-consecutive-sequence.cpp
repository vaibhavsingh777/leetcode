class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       if(n == 0) return 0;

       //insert all elements into the set
       unordered_set<int> st;
       for(int num : nums){
        st.insert(num);
       }

       int longest = 1;
       //iterate through the set
        for(auto it : st){
        //check if it is the starting element of any sequence
            int cnt;
            if(st.find(it-1) == st.end()){
             int cnt = 1;
             int x = it;

             //find the consecutive elements
              while(st.find(x + 1) != st.end()){
                x+=1;
                cnt+=1;
              }
            longest = max(longest, cnt);
            }
     
       }
       return longest;
    }
};
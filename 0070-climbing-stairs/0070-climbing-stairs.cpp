class Solution {
public:
    int climbStairs(int n) {
     if(n < 4) return n;

     int prev = 2;
     int prev1 = 3;

     for(int i = 3; i < n; i++){
        int curi = prev + prev1;
        prev = prev1;
        prev1 = curi;
     }
     return prev1;
    }
};
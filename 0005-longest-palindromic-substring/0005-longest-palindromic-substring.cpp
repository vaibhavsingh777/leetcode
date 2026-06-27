class Solution {
public:
    string longestPalindrome(string s) {
      if(s.length() == 1) return s;

        string LPS = "";
        int LPSlen = 0;

    for(int i = 0; i < s.length() - 1; i++){
        //odd case
        int l = i;
        int r = i;

        while(l>=0 && r <= s.length() && s[l]==s[r]){
        if((r-l+1) > LPSlen)
        {
            LPS = s.substr(l, r-l+1);
            LPSlen = r-l+1;            
        }
          l-=1;
          r+=1;
        } 
        //even case
        l = i;
        r = i+1;
        while(l>=0 && r <= s.length() && s[l]==s[r]){
        if((r-l+1) > LPSlen)
        {
            LPS = s.substr(l, r-l+1);
            LPSlen = r-l+1;            
        }
          l-=1;
          r+=1;
        } 
}

     return LPS;
    
    }
};
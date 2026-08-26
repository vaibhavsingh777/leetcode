class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        unordered_map<char,int> mp;
        int right = 1;
        int left = 0;

        for(int i = 0; i < n; ++i){
            if(mp.find(s[i]) != mp.end())
            {
                left = max(left, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            right = max(right, i - left + 1);
        }
        return right;
    }
};
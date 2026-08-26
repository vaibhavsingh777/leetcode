class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        unordered_map<char,int> mp; //storing char values with their last occurence
        int left = 0, answer = 1;

        for(int i = 0; i < n; ++i){
            if(mp.find(s[i]) != mp.end())
            {
                left = max(left, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            answer = max(answer, i - left + 1);
        }
        return answer;
    }
};
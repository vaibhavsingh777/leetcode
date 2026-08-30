class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length(), maxlen = 0;
        
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(const string& word : wordDict){
            maxlen = max(maxlen, (int)word.length());
        }


        for(int i = 1; i <= n; i++){
                for (int j = i - 1; j >= max(0, i - maxlen); j--) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; 
                }
        }
        
    }
    return dp[n];
    }
};
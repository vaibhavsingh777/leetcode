class Solution {
private:
int expandAroundCenter(const string& s, int left, int right){
    int count = 0;

    while(left >=0 && right < s.length() && s[left] == s[right]){
        count++;
        left--;
        right++;
    }
    return count;
}
public:
    int countSubstrings(string s) {
        int totalCount = 0;

        for(int i = 0; i < s.length(); i++){
            totalCount += expandAroundCenter(s, i, i);
            totalCount += expandAroundCenter(s, i, i + 1);
        }        

        return totalCount;

    }
};
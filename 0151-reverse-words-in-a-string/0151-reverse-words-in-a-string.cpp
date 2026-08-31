class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int left = 0, right = 0, i = 0;
        
        while (i < n) {
            // Skip leading/multiple spaces
            while (i < n && s[i] == ' ') i++;
            if (i == n) break; // We reached the end
            
            // Step 2 & 3: Copy the word over to the 'right' pointer to remove extra spaces
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            
            // Reverse the individual word we just copied
            reverse(s.begin() + left, s.begin() + right);
            
            // Add a single space after the word, and update 'left' for the next word
            s[right++] = ' ';
            left = right;
            i++;
        }
        
        // Remove the trailing space we added after the last word
        s.resize(right - 1);
        return s;
    }
};
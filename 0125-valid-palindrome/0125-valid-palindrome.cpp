class Solution {
private:
bool checkPalindrome(string& m){
int left = 0;
int right = m.length() - 1;

while(left < right)
{
    if(m[left] != m[right]){
        return false;
    }
    left++;
    right--;
}

return 1;
}

public:
    bool isPalindrome(string s) {
        string cleanedString = "";
        
        for(char c: s) {
            if(c >= 65 && c <= 90) {
                cleanedString += (c+32);
            }
            else if(c >= 97 && c <= 122) {
                cleanedString += c;
            }
            else if(c >= 48 && c <= 57) {
                cleanedString += c;
            }
        } // <-- Make sure your loop closes here!

        // Now that the whole string is cleaned, check if it's a palindrome
        return checkPalindrome(cleanedString); 
    }
};
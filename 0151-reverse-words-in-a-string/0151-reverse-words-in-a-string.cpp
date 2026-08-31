class Solution {
private: 

    void parser(const string& input, vector<string>& words) {
        string currentWord = "";
        int n = input.length();
        
        for (int i = 0; i < n; i++) {
            if (input[i] == ' ') {

                if (!currentWord.empty()) {
                    words.push_back(currentWord);
                    currentWord = ""; // Reset for the next word
                }
            } else {
                // Keep building the current word character by character
                currentWord += input[i];
            }
        }
        
        // Catch the very last word if the string didn't end with a space
        if (!currentWord.empty()) {
            words.push_back(currentWord);
        }
    }

public:
    string reverseWords(string s) {
        vector<string> words;
        
        // 1. Pass the string and our vector to the helper function
        parser(s, words);
        
        // 2. Reverse the array of words
        reverse(words.begin(), words.end());
        
        // 3. Reconstruct the final string with single spaces
        string answer = "";
        for (int i = 0; i < words.size(); i++) {
            answer += words[i];
            if (i < words.size() - 1) {
                answer += " "; // Add a space between words, but not at the end
            }
        }
        
        return answer;
    }
};
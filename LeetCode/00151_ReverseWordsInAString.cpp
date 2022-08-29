// https://leetcode.com/problems/reverse-words-in-a-string/


// Handling extra white spaces was tricky, leetcode discuss helped
class Solution {
public:
    string reverseWords(string s) {
        int sSize = s.length();
        int currWordIdx = 0, currParsingIdx = 0, wordInsertionIdx = 0;

		while(currParsingIdx < sSize) {
            // Skip the whitespaces
            while(currParsingIdx < sSize && s[currParsingIdx] == ' ')
                currParsingIdx++;
            
            if(currParsingIdx == sSize)
                break;

			// If some word has already been added to the string, add a space separator
            if(currWordIdx != 0)
                s[currWordIdx++] = ' ';

			// The index where word is supposed to be inserted
            wordInsertionIdx = currWordIdx;

			// Copy the non-whitespace characters to the string
            while(currParsingIdx < sSize && s[currParsingIdx] != ' ')
                s[currWordIdx++] = s[currParsingIdx++];
                reverse(s.begin() + wordInsertionIdx, s.begin() + (currWordIdx)); // Reverse the word
            }
        
        s.erase(s.begin() + currWordIdx, s.end()); // Erase the remaining characters
        reverse(s.begin(), s.end());
        return s;
    }
};
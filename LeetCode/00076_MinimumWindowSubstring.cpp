// https://leetcode.com/problems/minimum-window-substring/


// Solution using 2 maps
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.length(), tSize = t.length();
        
        if(tSize > sSize)
            return "";
        
        int windowInitIdx = 0, windowEndIdx = 0, numMatchedChars = 0;
        int sFreqMap[128] = {0}, tFreqMap[128] = {0};
        
        int minWindowSize = sSize + 1;
        string minWindowSubstring = s;
        
        for(char ch : t)
            tFreqMap[ch]++;
        
        while(windowEndIdx < sSize) {
            sFreqMap[s[windowEndIdx]]++; // Increase current visiting char frequency
            
            // If current char of string s occurs in string t and
            // Number of occurrences of current char of s <= number of occurrences of char char in t
            // We have a new marching character between s and t
            if(tFreqMap[s[windowEndIdx]] != 0 && 
               sFreqMap[s[windowEndIdx]] <= tFreqMap[s[windowEndIdx]])
                numMatchedChars++;
            
            // If all the characters have been matched, we will try to shrink the window
            if(numMatchedChars == tSize) {
                while(sFreqMap[s[windowInitIdx]] > tFreqMap[s[windowInitIdx]] || tFreqMap[s[windowInitIdx]] == 0) {
                    sFreqMap[s[windowInitIdx]]--;
                    windowInitIdx++;
                }
                
                int currWindowSize = windowEndIdx - windowInitIdx + 1;
                if(currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    minWindowSubstring = s.substr(windowInitIdx, currWindowSize);
                }
            }
            
            windowEndIdx++;
        }
        
        return (minWindowSize == sSize + 1) ? "": minWindowSubstring;
    }
};
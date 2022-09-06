// https://leetcode.com/problems/minimum-window-substring/

// This pattern can be used for solving any substring finding problems
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.length(), tSize = t.length();
        
        if(tSize > sSize)
            return "";
        
        int windowInitIdx = 0, windowEndIdx = 0, numMatchedChars = 0;
        int minWindowStart = 0, minWindowLen = sSize + 1;
        int freqMap[128] = {0};
        
        for(char ch : t)
            freqMap[ch]++;
        
        while(windowEndIdx < sSize) { // Window finding loop
            
            // If char at windowEndIdx in s also exists in t
            // Increase the number of matched characters
            if(freqMap[s[windowEndIdx]] > 0)
                numMatchedChars++;
            
            // If char at windowEndIdx in s exits in t, this will reduce the count by 1
            // as this character has been counted above
            // Else, this will make the count negative
            freqMap[s[windowEndIdx]]--;
            
            // If we have found all the matching characters
            // save the current window metadata and shrink window
            // until we encounter a character which is in t
            while(numMatchedChars == tSize) { // Window shrinking loop
                if(windowEndIdx - windowInitIdx + 1 < minWindowLen) {
                    minWindowStart = windowInitIdx;
                    minWindowLen = windowEndIdx - windowInitIdx + 1;
                }
                
                // We are removing the char at windowInitIdx in s
                // so we increment the count that was decremented outside this loop
                // The count will be positive if the char was in t
                // Else this would become 0
                freqMap[s[windowInitIdx]]++;
                
                // We removed a char which was in t
                if(freqMap[s[windowInitIdx]] > 0)
                    numMatchedChars--;
                
                windowInitIdx++;
            }
            
            windowEndIdx++;
        }
        
        return (minWindowLen == sSize + 1) ? "" : s.substr(minWindowStart, minWindowLen);
    }
};


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
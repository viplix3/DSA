// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// This pattern is a bit confusing to understand
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sSize = s.length();
        
        int windowInitIdx = 0, windowEndIdx = 0, repeatCharCount = 0;
        int freqMap[128] = {0};
        int maxWindowLen = 0;
        
        while(windowEndIdx < sSize) {
            freqMap[s[windowEndIdx]]++;
            
            if(freqMap[s[windowEndIdx]] > 1)
                repeatCharCount++;
            
            while(repeatCharCount > 0) {
                if(freqMap[s[windowInitIdx]] > 1)
                    repeatCharCount--;
                
                freqMap[s[windowInitIdx]]--;
                windowInitIdx++;
            }
            
            windowEndIdx++;
            maxWindowLen = max(windowEndIdx - windowInitIdx, maxWindowLen);
        }
        
        return maxWindowLen;
    }
};
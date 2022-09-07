// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// KMP algorithm
class Solution {
private:
    void fillLpsArray(vector<int>& lps, string str) {
        int sSize = str.length();
        lps[0] = 0;
        int currIdx = 1, currLen = 0;
        
        while(currIdx < sSize) {
            if(str[currIdx] == str[currLen]) {
                lps[currIdx++] = ++currLen;
            }
            else {
                if(currLen == 0)
                    lps[currIdx++] = 0;
                else
                    currLen = lps[currLen - 1];
            }
        }
        
    }
    
public:
    int strStr(string haystack, string needle) {
        int hSize = haystack.length(), nSize = needle.length();
        
        vector<int> lpsArray(nSize, 0);
        fillLpsArray(lpsArray, needle);
        int hIdx = 0, nIdx = 0;
        
        while(hIdx < hSize) {
            if(haystack[hIdx] == needle[nIdx])
                hIdx++, nIdx++;
            
            if(nIdx == nSize)
                return hIdx - nSize;
            
            if(haystack[hIdx] != needle[nIdx]) {
                if(nIdx == 0)
                    hIdx++;
                else
                    nIdx = lpsArray[nIdx - 1];
            }
        }
        
        return -1;
    }
};
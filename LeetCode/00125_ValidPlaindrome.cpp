// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int beginIdx = 0, endIdx = s.length();
        
        while(beginIdx < endIdx) {
            while(!isalnum(s[beginIdx]) && beginIdx < endIdx)
                beginIdx++;
            
            while(!isalnum(s[endIdx]) && endIdx > beginIdx)
                endIdx--;
            
            if(toupper(s[beginIdx]) != toupper(s[endIdx]))
                return false;
            
            beginIdx++, endIdx--;
        }
        
        return true;
    }
};
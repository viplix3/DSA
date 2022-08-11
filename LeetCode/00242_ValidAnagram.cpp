// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charFreqCount(27);
        
        for(char ch : s)
            charFreqCount[ch - 'a']++;
        
        for(char ch : t)
            charFreqCount[ch - 'a']--;
        
        for(int freq: charFreqCount)
            if(freq)
                return false;
        
        return true;
    }
};
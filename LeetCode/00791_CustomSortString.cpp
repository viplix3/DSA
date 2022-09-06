// https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        int sSize = s.length();
        int freqMap[27] = {0};
        
        for(char ch : s)
            freqMap[ch - 'a']++;
        
        string outString = "";
        
        for(char orderedChar : order) {
            while(freqMap[orderedChar - 'a'] != 0) {
                outString += orderedChar;
                freqMap[orderedChar - 'a']--;
            }
        }
        
        for(int i = 0; i < 27; i++)
            while(freqMap[i]--)
                outString += i + 'a';
        
        return outString;
    }
};
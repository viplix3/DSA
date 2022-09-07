// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToIntMap = { { 'I' , 1 },
                                                   { 'V' , 5 },
                                                   { 'X' , 10 },
                                                   { 'L' , 50 },
                                                   { 'C' , 100 },
                                                   { 'D' , 500 },
                                                   { 'M' , 1000 } };
        int sSize = s.length();
        int integerNum = romanToIntMap[s.back()];
        
        for(int i = sSize - 2; i >= 0; i--) {
            if(romanToIntMap[s[i]] < romanToIntMap[s[i + 1]])
                integerNum -= romanToIntMap[s[i]];
            else
                integerNum += romanToIntMap[s[i]];
        }
        
        return integerNum;
    }
};
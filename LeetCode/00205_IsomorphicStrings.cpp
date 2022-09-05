// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        int sSize1 = str1.length(), sSize2 = str2.length();
        
        if(sSize1 != sSize2)
            return false;
        
        vector<int> charMapping(128, -1);
        vector<bool> visitedInStr2(128, false);
        
        for(int idx = 0; idx < sSize1; idx++) {
            if(charMapping[str1[idx]] != -1) {
                if(charMapping[str1[idx]] != str2[idx])
                    return false;
            }
            else {
                if(visitedInStr2[str2[idx]])
                    return false;
                    
                charMapping[str1[idx]] = str2[idx];
                visitedInStr2[str2[idx]] = true;
            }
        }
        
        return true;
    }
};
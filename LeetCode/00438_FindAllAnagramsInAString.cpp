// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Thought of rolling hash (Rabin-Karp algorithm) but this is cleaner
// O(N) time, O(1) space
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pSize = p.length(), sSize = s.length();
        vector<int> anagramIdx;
        
        if(pSize > sSize)
            return anagramIdx;
        
        vector<int> patternCounter(26), stringCounter(26);
        
        for(int i = 0;  i < pSize; i++) {
            patternCounter[p[i] - 'a']++;
            stringCounter[s[i] - 'a']++;
        }
        
        if(patternCounter == stringCounter)
            anagramIdx.push_back(0);
        
        for(int windowEndIdx = pSize; windowEndIdx < sSize; windowEndIdx++) {
            stringCounter[s[windowEndIdx - pSize] - 'a']--;
            stringCounter[s[windowEndIdx] - 'a']++;
            
            if(patternCounter == stringCounter)
                anagramIdx.push_back(windowEndIdx - pSize + 1);
        }
        
        return anagramIdx;
    }
};
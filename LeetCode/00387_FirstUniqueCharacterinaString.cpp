// https://leetcode.com/problems/first-unique-character-in-a-string/

// GitHub CoPilot, elegant and concise but needs 2 traversal
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> charFreqCount(27);
		
		for(char ch : s)
			charFreqCount[ch - 'a']++;
		
		for(int i = 0; i < s.length(); i++)
			if(charFreqCount[s[i] - 'a'] == 1)
				return i;
		
		return -1;
	}
};

// My solution, janky as always, single traversal, better than the CoPilot one
class Solution {
public:
    int firstUniqChar(string s) {
        /*
            -1 -> Didn't occur
            [0, sSize] -> Occurred 1 time, occurrence index
            -1 -> Occurred multiple times
        */
        
        vector<int> charOccurrenceMap(27, -1);
        int sSize = s.length(), sIdx = sSize - 1;
        
        while(sIdx >= 0) {
            int prevOccIdx = charOccurrenceMap[s[sIdx] - 'a'];
            if(prevOccIdx != -1)
                charOccurrenceMap[s[sIdx] - 'a'] = -2;
            else
                charOccurrenceMap[s[sIdx] - 'a'] = sIdx;
            sIdx--;
        }
        
        int nonRepeatingCharIdx = INT_MAX;
        
        for(int i = 0; i < 27; i++)
            if(charOccurrenceMap[i] >= 0)
                nonRepeatingCharIdx = min(charOccurrenceMap[i], nonRepeatingCharIdx);
        
        return (nonRepeatingCharIdx == INT_MAX) ? -1 : nonRepeatingCharIdx;
    }
};
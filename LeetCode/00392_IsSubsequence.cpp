// https://leetcode.com/problems/is-subsequence/

// GitHub CoPilot solution, elegant and concise
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int ssize = s.size();
		int tsize = t.size();
		int sindex = 0;
		int tindex = 0;
		
		while(sindex < ssize && tindex < tsize) {
			if(s[sindex] == t[tindex])
				sindex++;
			tindex++;
		}
		
		return sindex == ssize;
	}
};

// My solution, janky
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        
        if(tLen == 0 && sLen == 0)
            return true;
        
        if(sLen > tLen)
            return false;
        
        int sItr = 0;
        
        for(int i = 0; i < tLen; i++) {
            if(t[i] == s[sItr])
                sItr++;
            if(sItr == sLen)
                return true;
        }
        
        return false;
    }
};
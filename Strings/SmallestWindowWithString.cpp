// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

constexpr int CHARS = 256;
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string str, string pattern)
    {
		if(str.length() < pattern.length())
			return "-1";

		int pattern_occ[CHARS] = {0};
		int str_occ[CHARS] = {0};

		for(int i=0; i<pattern.length(); i++)
			pattern_occ[pattern[i]] += 1;

		int windowInit = 0, windowEnd = 0;
		int numMatched = 0;
		int minWindowSize = INT_MAX;
		string windowSubStr = "";

		while(windowEnd < str.length()) {
			str_occ[str[windowEnd]] += 1;

			// If current string character is present in the pattern AND 
			// Number of occurrences of the character so far in string is <= number of occurrences in pattern, a match is found
			if(pattern_occ[str[windowEnd]] != 0 && str_occ[str[windowEnd]] <= pattern_occ[str[windowEnd]])
				numMatched += 1;

			// If number of matches found are equal to the length of pattern, we have a candidate window
			if(numMatched == pattern.length()) {
				// SHRINKING THE WINDOW
				// If number of occurrences (so far) of the character at windowInit in string > occurences of character in pattern OR
				// The character at windowInit of string is not in the pattern, we will shrink our window
				while(str_occ[str[windowInit]] > pattern_occ[str[windowInit]] || pattern_occ[str[windowInit]] == 0) {
					str_occ[str[windowInit]] -= 1;
					windowInit += 1; // Move window init to right to shrink the window
				}

				int currWindowSize = windowEnd - windowInit + 1;
				if(currWindowSize < minWindowSize) {
					minWindowSize = currWindowSize;
					windowSubStr = str.substr(windowInit, currWindowSize);
				}
			}

			windowEnd += 1;
		}
		
		if(minWindowSize == INT_MAX)
			return "-1";
		return windowSubStr;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
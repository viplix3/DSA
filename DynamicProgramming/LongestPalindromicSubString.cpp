// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    string longestPalin (string str) {
        int strLen = str.length();
        vector<vector<bool>> isPalin(strLen, vector<bool>(strLen, false));
        int palinStartIdx = 0, palinLength = 1;

        for(int i = 0; i < strLen; i++) {
            // Single character is always plaindrome with itself
            isPalin[i][i] = true;

			// If current string character is same as next string character
            // we have a plaindrome
            if(str[i] == str[i + 1]) {
                isPalin[i][i + 1] = true;
                palinStartIdx = i;
                palinLength = 2;
            }
        }


        // Trying to find greater than length 2 palindromes
        for(int currPalinLength = 3; currPalinLength <= strLen; currPalinLength++) {
            for(int currPalinStartIdx = 0; currPalinStartIdx < strLen - currPalinLength + 1; currPalinStartIdx++) {
                int currPalinEndIdx = currPalinStartIdx + currPalinLength - 1;

                if(isPalin[currPalinStartIdx + 1][currPalinEndIdx - 1] && str[currPalinStartIdx] == str[currPalinEndIdx]) {
                    isPalin[currPalinStartIdx][currPalinEndIdx] = true;

                    if(currPalinLength > palinLength) {
                        palinStartIdx = currPalinStartIdx;
                        palinLength = currPalinLength;
                    }
                }
            }
        }

        string palinString = str.substr(palinStartIdx, palinLength);
        return palinString;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
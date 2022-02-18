// https://leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string say(string countString) {
        string sayString = "";
        
        int currIdx = 0, endIdx = countString.length();
        
        char currChar = countString[0];
        int charCount = 1;
        
        while(currIdx < endIdx) {
            
            // Getting frequency of current character for saying it
            while(countString[currIdx] == countString[currIdx + 1]) {
                charCount += 1;
                currIdx += 1;
            }
            
            sayString += (to_string(charCount) + currChar);
            
            charCount = 1;
            currIdx += 1;
            currChar = countString[currIdx];
        }

        return sayString;
    }
    
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        
        string countString = countAndSay(n - 1);
        return say(countString);
    }
};

int main() {
	int numTestCases;
	cin >> numTestCases;

	Solution solObj = Solution();

	while(numTestCases) {
		int num;
		cin >> num;

		cout << solObj.countAndSay(num) << endl;

		numTestCases -= 1;
	}

}
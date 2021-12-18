#include <bits/stdc++.h>
using namespace std;

string LCS(string str1, string str2, int str1Length, int str2Length) {
	vector<vector<int>> lcsTable(str1Length + 1, vector<int>(str2Length + 1, 0));
	string lcsString = "";

	for(int i = 1; i <= str1Length; i++) {
		for(int j = 1; j <= str2Length; j++) {
			if(str1[i-1] == str2[j-1]) {
				lcsTable[i][j] = 1 + lcsTable[i-1][j-1];
			}
			else
				lcsTable[i][j] = max(lcsTable[i-1][j], lcsTable[i][j-1]);
		}
	}

	int i = str1Length, j = str2Length;
	while(i > 0 && j > 0) {
		if(str1[i-1] == str2[j-1]) {
			lcsString += str1[i-1];
			i -= 1, j -=1;
		}
		else
			if(lcsTable[i-1][j] > lcsTable[i][j-1])
				i -= 1;
			else
				j -= 1;
	}

	reverse(lcsString.begin(), lcsString.end());
	return lcsString;
}

string getLongestPalindromicSubsequence(string str) {
	int strLength = str.length();
	string reverseStr = str;

	reverse(reverseStr.begin(), reverseStr.end());
	string lcsString = LCS(str, reverseStr, strLength, strLength);

	return lcsString;
}

int main() {
	string testString, palindromicSubsequence;

	testString = "GEEKS";
	cout << "Input string: " << testString << endl;
	palindromicSubsequence = getLongestPalindromicSubsequence(testString);
	cout << "Longest palindromic subsequence for given string: " << palindromicSubsequence << endl;
	cout << endl;

	testString = "GEEKSFORGEEKS";
	cout << "Input string: " << testString << endl;
	palindromicSubsequence = getLongestPalindromicSubsequence(testString);
	cout << "Longest palindromic subsequence for given string: " << palindromicSubsequence << endl;
	cout << endl;

	return 0;
}
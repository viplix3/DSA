#include <bits/stdc++.h>
using namespace std;

string parseLCS(vector<vector<int>>& lcsTable, string str1, int str1Length, string str2, int str2Length) {
	int i = str1Length, j = str2Length;
	string lcs = "";

	while(i > 0 && j > 0) {
		if(str1[i-1] == str2[j-1] && i != j) {
			lcs += str1[i-1];
			i -= 1, j -=1;
		}
		else if(lcsTable[i-1][j] > lcsTable[i][j-1])
			i -= 1;
		else
			j -=1;
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}

string findLongestRepeatingSubsequence(string str) {
	int strLength = str.length();
	vector<vector<int>> lcsTable(strLength + 1, vector<int>(strLength + 1, 0));

	for(int i = 1; i <= strLength; i++) {
		for(int j = 1; j <= strLength; j++) {
			if(str[i-1] == str[j-1] && (i != j))
				lcsTable[i][j] = 1 + lcsTable[i-1][j-1];
			else
				lcsTable[i][j] = max(lcsTable[i-1][j], lcsTable[i][j-1]);
		}
	}

	if(lcsTable[strLength][strLength] == 0)
		return "";
	
	return parseLCS(lcsTable, str, strLength, str, strLength);
}

int main() {
	string testString, repeatingSubsequence;

	testString = "AABB";
	cout << "Input string: " << testString << endl;
	repeatingSubsequence = findLongestRepeatingSubsequence(testString);
	cout << "Longest repeating subsequence in given string: " << repeatingSubsequence << endl;
	cout << endl;

	testString = "AA";
	cout << "Input string: " << testString << endl;
	repeatingSubsequence = findLongestRepeatingSubsequence(testString);
	cout << "Longest repeating subsequence in given string: " << repeatingSubsequence << endl;
	cout << endl;

	testString = "abs";
	cout << "Input string: " << testString << endl;
	repeatingSubsequence = findLongestRepeatingSubsequence(testString);
	cout << "Longest repeating subsequence in given string: " << repeatingSubsequence << endl;
	cout << endl;

	return 0;
}
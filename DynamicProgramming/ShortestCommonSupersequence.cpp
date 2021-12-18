#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int str1Length, int str2Length, vector<vector<int>>& memoTable) {
	if(memoTable[str1Length][str2Length] == -1) {
		if(str1Length == 0 || str2Length == 0)
			memoTable[str1Length][str2Length] = 0;
		else {
			if(str1[str1Length-1] == str2[str2Length-1])
				memoTable[str1Length][str2Length] = 1 + LCS(str1, str2, str1Length-1, str2Length-1, 
																memoTable);
			else
				memoTable[str1Length][str2Length] = max( LCS(str1, str2, str1Length-1, str2Length, memoTable),
														 LCS(str1, str2, str1Length, str2Length-1, memoTable));
		}
	}

	return memoTable[str1Length][str2Length];
}

int shortestCommonSuperSequence(string str1, string str2) {
	int str1Length = str1.length(), str2Length = str2.length();
	vector<vector<int>> memoTable(str1Length + 1, vector<int>(str2Length + 1, -1));

	int lcsLength = LCS(str1, str2, str1Length, str2Length, memoTable);
	return (str1Length + str2Length - lcsLength);

}

int main() {
	string testString1, testString2;

	testString1 = "GEEK";
	testString2 = "EFGK";
	cout << "String 1: " << testString1 << endl;
	cout << "String 2: " << testString2 << endl;
	cout << "Shortest common supersequence length for the given strings: " << shortestCommonSuperSequence(testString1, testString2);
	cout << endl << endl;

	testString1 = "GEEK";
	testString2 = "GFEK";
	cout << "String 1: " << testString1 << endl;
	cout << "String 2: " << testString2 << endl;
	cout << "Shortest common supersequence length for the given strings: " << shortestCommonSuperSequence(testString1, testString2);
	cout << endl << endl;

	testString1 = "AGGTAB";
	testString2 = "GXTXAYB";
	cout << "String 1: " << testString1 << endl;
	cout << "String 2: " << testString2 << endl;
	cout << "Shortest common supersequence length for the given strings: " << shortestCommonSuperSequence(testString1, testString2);
	cout << endl << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int getLCS(string str1, string str2, int str1Length, int str2Length, vector<vector<int>>& memoTable) {
	if(memoTable[str1Length][str2Length] == -1) {

		if(str1Length == 0 || str2Length == 0)
			memoTable[str1Length][str2Length] = 0;
		else {
			if(str1[str1Length - 1] == str2[str2Length - 1])
				memoTable[str1Length][str2Length] =  1 + getLCS(str1, str2, str1Length - 1,
																str2Length - 1, memoTable); // Find LCS of remaining string
			else
				memoTable[str1Length][str2Length] = max( getLCS(str1, str2, str1Length - 1, str2Length, memoTable), 
															getLCS(str1, str2, str1Length, str2Length - 1, memoTable));
		}
	}

	return memoTable[str1Length][str2Length];
}

int getMinOps(string str1, string str2) {
	int str1Length = str1.length(), str2Length = str2.length();
	vector<vector<int>> memoTable(str1Length + 1, vector<int>(str2Length + 1, -1));

	int longestCommonSubsequence = getLCS(str1, str2, str1Length, str2Length, memoTable);
	int numOps = (str1Length - longestCommonSubsequence) + (str2Length - longestCommonSubsequence);

	return numOps;
}

int main() {
	string testString1, testString2;

	testString1 = "GEEK";
	testString2 = "EFGK";
	cout << "String 1: " << testString1 << endl;
	cout << "String 2: " << testString2 << endl;
	cout << "Minimum number of insert/delete operations required to convert one string to other: ";
	cout << getMinOps(testString1, testString2) << endl;
	cout << endl;

	testString1 = "GEEK";
	testString2 = "GFEK";
	cout << "String 1: " << testString1 << endl;
	cout << "String 2: " << testString2 << endl;
	cout << "Minimum number of insert/delete operations required to convert one string to other: ";
	cout << getMinOps(testString1, testString2) << endl;
	cout << endl;

	return 0;
}
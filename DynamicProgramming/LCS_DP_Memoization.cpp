#include<bits/stdc++.h>
using namespace std;

int LCS_DP(string str1, string str2, int lenStr1, int lenStr2, vector<vector<int>>& memo) {
	if(memo[lenStr1][lenStr2] != -1)
		return memo[lenStr1][lenStr2]; // Some pre-computer sub-problem

	if(lenStr1 == 0 || lenStr2 == 0) // Base case
		memo[lenStr1][lenStr2] = 0;
	
	else {
		if(str1[lenStr1 - 1] == str2[lenStr2 - 1])
			memo[lenStr1][lenStr2] = (1 + LCS_DP(str1, str2, lenStr1-1, lenStr2-1, memo));
		else
			memo[lenStr1][lenStr2] = max( LCS_DP(str1, str2, lenStr1-1, lenStr2, memo),
										  LCS_DP(str1, str2, lenStr1, lenStr2-1, memo) );
	}

	return memo[lenStr1][lenStr2];
}

int LCS(string str1, string str2, int lenStr1, int lenStr2) {
	vector<vector<int>> memo(lenStr1+1, vector<int>(lenStr2+2, -1));
	return LCS_DP(str1, str2, lenStr1, lenStr2, memo);
}


int main() {
	string str1, str2;
	cout << "Enter string 1: ";
	cin >> str1;

	cout << "Enter string 2: ";
	cin >> str2;
	
	cout << "Length of LCS for given strings: " << LCS(str1, str2, str1.length(), str2.length()) << endl;

	return 0;
}

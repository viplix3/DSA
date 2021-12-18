#include<bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int lenStr1, int lenStr2) {
	vector<vector<int>> lcs(lenStr1 + 1, vector<int>(lenStr2 + 1, 0));

	for(int i = 1; i <= lenStr1; i++) {
		for(int j = 1; j <= lenStr2; j++) {
			if(str1[i-1] == str2[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	return lcs[lenStr1][lenStr2];
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


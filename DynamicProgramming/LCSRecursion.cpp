#include<bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int lenStr1, int lenStr2) {
	if(lenStr1 == 0 || lenStr2 == 0)
		return 0;
	
	if(str1[lenStr1 - 1] == str2[lenStr2 - 1])
		return (1 + LCS(str1, str2, lenStr1-1, lenStr2-1));
	else
		return max( LCS(str1, str2, lenStr1-1, lenStr2),
					LCS(str1, str2, lenStr1, lenStr2-1) );
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
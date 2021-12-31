#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int beginIdx, int endIdx) {

	while(beginIdx < endIdx) {
		if(str[beginIdx] != str[endIdx])
			return false;
		
		beginIdx += 1;
		endIdx -= 1;
	}

	return true;
}

int getPalindromicPartitions(string str, int beginIdx, int endIdx) {
	if(isPalindrome(str, beginIdx, endIdx))
		return 0;

	int minCuts = INT_MAX;
	for(int i = beginIdx; i < endIdx; i++) {
		int numCuts = getPalindromicPartitions(str, beginIdx, i) + getPalindromicPartitions(str, i + 1, endIdx);
		minCuts = min(numCuts + 1, minCuts);
	}
	return minCuts;
}

int main() {
	string testString;

	testString = "geek";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString, 0, testString.length() - 1) << endl;
	cout << endl;

	testString = "abbac";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString, 0, testString.length() - 1) << endl;
	cout << endl;

	testString = "abcde";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString, 0, testString.length() - 1) << endl;
	cout << endl;

	testString = "aaaa";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString, 0, testString.length() - 1) << endl;
	cout << endl;

	testString = "abbabbc";
	cout << "Input string: " << testString << endl;
	cout << "Num partitions required to make string palindrome: " << getPalindromicPartitions(testString, 0, testString.length() - 1) << endl;
	cout << endl;

	return 0;
}